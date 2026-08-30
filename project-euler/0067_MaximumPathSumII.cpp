#include <bits/stdc++.h>

using namespace std;


int solve(const vector<vector<int>> &v, vector<vector<int>> &memo, int i = 0, int j = 0)
{
    if (i == v.size())
        return 0;

    if (memo[i][j] != -1)
        return memo[i][j];

    int res = v[i][j] + max(solve(v, memo, i + 1, j), solve(v, memo, i + 1, j + 1));
    memo[i][j] = res;
    return res;
}


int main()
{
    ifstream in("0067_triangle.txt");

    vector<vector<int>> v;
    string line;
    while (getline(in, line))
    {
        istringstream iss(line);
        int temp;
        v.push_back({});
        while (iss >> temp)
        {
            v.back().push_back(temp);
        }
    }

    vector<vector<int>> memo(v.size(), vector<int>(v.size(), -1));

    auto res = solve(v, memo);
    cout << "res: " << solve(v, memo) << endl;
    return 0;
}
