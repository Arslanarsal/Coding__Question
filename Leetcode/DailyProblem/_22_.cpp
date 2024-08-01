#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        int n = names.size();
        vector<pair<int, string>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({heights[i], names[i]});
        }
        sort(v.begin(), v.end(), [](const pair<int, string> &a, const pair<int, string> &b)
             { return a.first > b.first; });
        for (int i = 0; i < n; i++)
        {
            names[i] = v[i].second;
        }
        return names;
    }
};

int main()
{

    return 0;
}