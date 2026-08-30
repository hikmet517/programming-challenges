#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;


uint64_t iter(const vector<vector<uint64_t>> &matrix, int i = 0, int j = 0)
{
    if (i < matrix.size() && j < matrix.size())
        return matrix[i][j] + min(iter(matrix, i + 1, j), iter(matrix, i, j + 1));
    else if (i < matrix.size())
        return matrix[i][j] + iter(matrix, i + 1, j);
    else if (j < matrix.size())
        return matrix[i][j] + iter(matrix, i, j + 1);
    else
        return 0;
}


int main()
{
    vector<vector<uint64_t>> data;

    ifstream fd("0081_matrix.txt");
    string line;
    while (getline(fd, line))
    {
        string num;
        data.push_back({});
        istringstream iss(line);
        while (getline(iss, num, ','))
        {
            data.back().push_back(stoi(num));
        }
    }

    for (int i = 1; i < data.size(); i++)
    {
        data[i][0] += data[i - 1][0];
    }

    for (int j = 1; j < data[0].size(); j++)
    {
        data[0][j] += data[0][j - 1];
    }

    for (int i = 1; i < data.size(); i++)
    {
        for (int j = 1; j < data[i].size(); j++)
        {
            data[i][j] += min(data[i - 1][j], data[i][j - 1]);
        }
    }
    cout << data[data.size() - 1][data[0].size() - 1] << endl;

    ofstream out("081_sil.txt");
    for (const auto &row : data)
    {
        for (const auto &d : row)
        {
            out << setw(8) << d << " ";
        }
        out << "\n";
    }

    return 0;
}
