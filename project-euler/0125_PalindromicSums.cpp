#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// exponentiation by squaring
template <typename T>
T ipow(T base, uint32_t exp)
{
    T result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;

        base *= base;
        exp >>= 1;
    }
    return result;
}

template <typename T>
uint8_t get_digit(T num, uint32_t index)
{
    return (num / ipow(10, index)) % 10;
}

template <typename T>
int get_digit_num(T num)
{
    int count = 0;
    do
    {
        ++count;
        num /= 10;
    } while (num != 0);
    return count;
}

template <typename T>
bool is_palindrome(T num)
{
    int n = get_digit_num(num);
    for (int i = 0; i < n; i++)
    {
        if (get_digit(num, i) != get_digit(num, n - i - 1))
        {
            return false;
        }
    }
    return true;
}

template <typename T>
vector<T> generate_squares(uint32_t min, uint32_t max)
{
    vector<T> temp;
    temp.reserve(max - min + 1);
    for (T i = min; i <= max; i++)
    {
        temp.push_back(ipow(i, 2));
    }
    return temp;
}


template <typename T>
vector<T> generate_palindromes(uint32_t min, uint32_t max)
{
    vector<T> temp;
    temp.reserve(max - min + 1);
    for (T i = min; i <= max; i++)
    {
        if (is_palindrome(i))
        {
            temp.push_back(i);
        }
    }
    return temp;
}

template <typename T>
bool represented_by_consecutive_sums(const vector<T> &nums, T target)
{
    auto end = lower_bound(nums.begin(), nums.end(), target);
    if (end != nums.end())
        end++;

    auto beg = prev(end);
    int count = 0;
    while (true)
    {
        if (beg > end)
            return false;

        T sum = accumulate(beg, end, static_cast<T>(0));
        if (sum > target)
        {
            if (end != nums.begin())
                end--;
            else
                return false;
        }
        else if (sum < target)
        {
            if (beg != nums.begin())
                beg--;
            else
                return false;
        }
        else
        {
            if (distance(beg, end) > 1)
                return true;
            else
                return false;
        }
        count++;
    }
}

int main()
{
    auto squares = generate_squares<uint64_t>(1, ipow(10, 4));
    auto palindromes = generate_palindromes<uint64_t>(0, ipow(10, 8));

    uint64_t sum = 0;
    for (auto i : palindromes)
    {
        if (represented_by_consecutive_sums(squares, i))
        {
            cout << i << "\n";
            sum += i;
        }
    }
    cout << "sum: " << sum << "\n";

    return 0;
}
