#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;


class CountingSummations
{
    vector<vector<int>> dat = {
        {1},          // 1: ((1))
        {1, 1},       // 2: ((1 1)) ((2))
        {1, 1, 1},    // 3: ((1,1,1)) ((2,1)) ((3))
        {1, 2, 1, 1}, // 4: ((1,1,1,1)) ((2,2) (2,1,1)) ((3,1)) ((4))
    };

  public:
    int sumNum(int num)
    {
        return accumulate(dat[num - 1].begin(), dat[num - 1].end(), 0);
    }

    int sumLessThan(int target, int lessThan)
    {
        int sum = 0;
        lessThan = min(target, lessThan);
        for (int i = 0; i < lessThan; i++)
        {
            sum += dat[target - 1][i];
        }
        return sum;
    }

    vector<int> newRow(int num)
    {
        vector<int> row;
        row.reserve(num);
        row.push_back(1);
        for (int i = 1; i < num - 1; i++)
        {
            row.push_back(sumLessThan(num - i - 1, i + 1));
        }
        row.push_back(1);
        return row;
    }

    int get(int num)
    {
        if (num <= dat.size())
        {
            return sumNum(num) - 1;
        }
        else
        {
            for (int i = dat.size() + 1; i <= num; i++)
            {
                dat.push_back(newRow(i));
            }
            return sumNum(num) - 1;
        }
    }
};


int main()
{
    CountingSummations c;
    cout << "result: " << c.get(100) << "\n";
    return 0;
}
