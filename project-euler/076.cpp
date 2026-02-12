#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<short>> nextIter(vector<short> &v)
{
    vector<vector<short>> res;
    
    vector<short> temp = v;
    temp[0] = temp[0] + temp[1];
    temp.erase(temp.begin()+1);
    res.push_back(temp);
    
    for(int i=1; i<v.size()-1; i++)
    {
        if(v[i-1] >= v[i]+v[i+1])
        {
            vector<short> temp = v;
            temp[i] = temp[i] + temp[i+1];
            temp.erase(temp.begin()+i+1);
            res.push_back(temp);
        }
    }
    return res;
}

vector<vector<short>> iterAll(vector<vector<short>>v)
{
    vector<vector<short>> res;
    for(auto& i : v)
    {
        auto n = nextIter(i);
        for(auto& j : n)
        {
            if(find(res.begin(),res.end(),j) == res.end())
            {
                res.push_back(j);
            }
        }
    }
    return res;
}


void print(vector<vector<short>> &v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << "[";
        for(int j = 0; j < v[i].size()-1; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << v[i].back() << "]\n";
    }
    cout << v.size()-1 << endl;
}

int main(int argc, char **argv)
{
    
    int n = atoi(argv[1]);
    vector<vector<short>> res{vector<short>(n,1)};
    unsigned long long int sum = res.size();
    for(int i=0; i<n-2; i++)
    {
        auto temp = iterAll(res);
        res = temp;
        sum += res.size();
        cout << i << "/" << n-2 << endl;
    }
    cout << sum << endl;
    // print(res);

    
    
    
    
    /*
    vector<vector<short>>list = {{1}};
    for(int i = 0; i < n-1; i++)
    {
        vector<vector<short>>temp;
        temp.reserve(2*list.size());
        for(int j = 0; j<list.size(); j++)
        {
            temp.push_back(list[j]);
            temp.back().push_back(1);   // extend hali (sona)
            temp.push_back(list[j]);
            temp.back().back() += 1;    // incremet hali
        }
        
        list.clear();
        list.reserve(temp.size());
        for(int j = 0; j<temp.size(); j++)
        {
            if(is_sorted(temp[j].begin(), temp[j].end(), greater<short>()))
            {
                list.push_back(temp[j]);
            }
        }
        
    }
    
    for(int i = 0; i < list.size(); i++)
    {
        cout << "[";
        for(int j = 0; j < list[i].size(); j++)
        {
            cout << list[i][j] << " ";
        }
        cout << "]\n";
    }
    cout << list.size()-1 << endl;
    */
    
    return 0;
}


