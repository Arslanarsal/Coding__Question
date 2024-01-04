#include <bits/stdc++.h>
using namespace std;
string frequencySort(string s)
{
    string ans = "";
    map<char, int> mp;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
    }
    vector<pair<char, int>> vec(mp.begin(), mp.end());

    sort(vec.begin(), vec.end(), [](const auto &a, const auto &b)
         { return a.second > b.second; });

    for (const auto &pair : vec)
    {
        n = pair.second;
        int j = 0;
        while (j < n)
        {
            ans += pair.first;
            j++;
        }
    }
    return ans;
}
int main()
{
    string s = "aaabbBBccc";
    cout << frequencySort(s);

    return 0;
}