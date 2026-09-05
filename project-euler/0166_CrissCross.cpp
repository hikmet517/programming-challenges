// g++ -O2 0166_CrissCross.cpp && ./a.out

#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;


class Vec4
{
    array<uint8_t, 4> data;

  public:
    Vec4(int d)
    {
        data[0] = d % 10;
        data[1] = (d / 10) % 10;
        data[2] = (d / 100) % 10;
        data[3] = (d / 1000) % 10;
    };

    int operator[](int index) const noexcept
    {
        return data[4 - index - 1];
    }

    uint8_t sum() const noexcept
    {
        return data[0] + data[1] + data[2] + data[3];
    }

    friend ostream &operator<<(ostream &os, const Vec4 &v)
    {
        os << v[0] << ", " << v[1] << ", " << v[2] << ", " << v[3];
        return os;
    }
};


const int ANY = 255;


vector<Vec4> generateVecs(uint8_t sum = ANY, uint8_t start = ANY, uint8_t end = ANY)
{
    vector<Vec4> temp;
    for (int i = 0; i < 10000; i++)
    {
        auto v = Vec4{i};
        if ((start == ANY || v[0] == start) && (end == ANY || v[3] == end) &&
            (sum == ANY || v.sum() == sum))
        {
            temp.push_back(v);
        }
    }
    return temp;
}


int count(int sum)
{
    int total = 0;

    // clockwise: top-left, top-right, bottom-right, bottom-left
    // 0 -- 1
    // |    |
    // 3 -- 2
    auto cornerVecs = generateVecs(ANY, ANY, ANY);

    for (const auto &cornerVec : cornerVecs)
    {
        auto vecTop = generateVecs(sum, cornerVec[0], cornerVec[1]);
        auto vecRight = generateVecs(sum, cornerVec[1], cornerVec[2]);
        auto vecBottom = generateVecs(sum, cornerVec[3], cornerVec[2]);
        auto vecLeft = generateVecs(sum, cornerVec[0], cornerVec[3]);
        auto vecDiag1 = generateVecs(sum, cornerVec[0], cornerVec[2]);
        auto vecDiag2 = generateVecs(sum, cornerVec[3], cornerVec[1]);

        for (const auto &vTop : vecTop)
        {
            for (const auto &vBottom : vecBottom)
            {
                for (const auto &vLeft : vecLeft)
                {
                    for (const auto &vRight : vecRight)
                    {
                        for (const auto &vDiag1 : vecDiag1)
                        {
                            for (const auto &vDiag2 : vecDiag2)
                            {
                                // check cols and rows inside the cage
                                bool col1OK =
                                    (vTop[1] + vDiag1[1] + vDiag2[1] + vBottom[1] == sum);
                                bool col2OK =
                                    (vTop[2] + vDiag2[2] + vDiag1[2] + vBottom[2] == sum);
                                bool row1OK =
                                    (vLeft[1] + vDiag1[1] + vDiag2[2] + vRight[1] == sum);
                                bool row2OK =
                                    (vLeft[2] + vDiag2[1] + vDiag1[2] + vRight[2] == sum);
                                if (col1OK && col2OK && row1OK && row2OK)
                                {
                                    total++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return total;
}


int main()
{
    int sum = 0;
    for (int i = 0; i <= 17; i++)
    {
        auto res = count(i);
        cout << "sum " << i << ": " << res << "\n";
        sum += res;
    }
    sum *= 2;
    auto res18 = count(18);
    cout << "sum 18: " << res18 << "\n";
    sum += res18;
    cout << "res: " << sum << "\n";

    return 0;
}
