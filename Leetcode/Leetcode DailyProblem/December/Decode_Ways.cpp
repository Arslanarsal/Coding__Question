#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> dp;

int solve(int i, string s)
{
    if (s[i] == '0')
    {
        return 0;
    }
    if (i >= s.size() - 1)
    {
        return 1;
    }
    if (dp.find(i) != dp.end())
    {
        return dp[i];
    }

    int ans = solve(i + 1, s);
    if (stoi(s.substr(i, 2)) <= 26)
    {
        ans += solve(i + 2, s);
    }
    return dp[i] = ans;
}

int numDecodings(string s)
{
    return solve(0, s);
}

int main()
{
    cout << numDecodings("06");
    return 0;
}