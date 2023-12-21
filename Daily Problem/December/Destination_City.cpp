#include <bits/stdc++.h>
using namespace std;

string destCity(vector<vector<string>> &paths)
{
    unordered_set<string> _set;
    for (int i = 0; i < paths.size(); i++)
    {
        _set.insert(paths[i][0]);
    }
    for (int i = 0; i < paths.size(); i++)
    {
        if (_set.find(paths[i][1]) == _set.end())
            return paths[i][1];
    }
    return "";
}

int main()
{

    return 0;
}