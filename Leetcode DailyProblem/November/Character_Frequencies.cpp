#include <bits/stdc++.h>
using namespace std;

int minDeletions(string s)
{
    map<char, int> mp;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }

    int ans = 0;
    bool flage = false;
    for (int i = 0; i < mp.size(); i++)
    {
        for (int j = i + 1; j < mp.size(); j++)
        {
            if (mp[s[i]] == mp[s[j]])
            {
                ans++;
                flage = true;
            }
        }
        if (flage)
        {
            return ans;
        }
    }
    return ans;
}

int main()
{
    string s = "ceabaacb";
    cout << minDeletions(s);

    return 0;
}