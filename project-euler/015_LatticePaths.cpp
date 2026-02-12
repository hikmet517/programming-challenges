#include <cstdint>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int size = 21;
    vector<vector<uint64_t>> v(size, vector<uint64_t>(size));
    for (int i=0; i<size; i++)
        v[i][0] = 1;
    for (int j=0; j<size; j++)
        v[0][j] = 1;

    for (int i=1; i<size; i++) {
        for (int j=1; j<size; j++) {
            v[i][j] = v[i-1][j] + v[i][j-1];
        }
    }

    // for (int i=0; i<size; i++) {
    //     for (int j=0; j<size; j++) {
    //         cout << setw(12) << v[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << endl;

    cout << v[size-1][size-1] << endl;

    return 0;
}
