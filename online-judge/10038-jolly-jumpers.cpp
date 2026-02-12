#include <iostream>
#include <vector>


using namespace std;


bool is_jolly(const vector<int>& nums)
{
    if (nums.size() == 1)
        return true;

    vector<bool> diffs(nums.size(), false);

    for (int i = 1; i < nums.size(); i++) {
        int diff = abs(nums[i] - nums[i - 1]);
        if (diff < diffs.size())
            diffs[diff] = true;
    }

    for (int i = 1; i < diffs.size(); i++) {
        if (!diffs[i])
            return false;
    }

    return true;
}


int main()
{
    int n;
    while (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            nums[i] = x;
        }
        if (is_jolly(nums))
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;
    }
    return 0;
}
