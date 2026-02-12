#include <bits/stdc++.h>

using namespace std;

int solve(const vector<vector<int>>& v, vector<vector<int>>& memo, int i=0, int j=0) {
    if (i == v.size())
        return 0;

    if (memo[i][j] != -1)
        return memo[i][j];
    
    int res = v[i][j] + max( solve(v, memo, i+1, j),  solve(v, memo, i+1, j+1));
    memo[i][j] = res;
    return res;
}

int main() {
    vector<vector<int>> v = {{75},
                             {95, 64},
                             {17, 47, 82},
                             {18, 35, 87, 10},
                             {20,  4, 82, 47, 65},
                             {19,  1, 23, 75,  3, 34},
                             {88,  2, 77, 73,  7, 63, 67},
                             {99, 65,  4, 28,  6, 16, 70, 92},
                             {41, 41, 26, 56, 83, 40, 80, 70, 33},
                             {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
                             {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
                             {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
                             {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
                             {63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
                             { 4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23}};

    vector<vector<int>> memo(v.size(), vector<int>(v.size(), -1));

    auto res = solve(v, memo);
    cout << "res: " << solve(v, memo) << endl;
    return 0;
}
