#include <bits/stdc++.h>
using namespace std;

int right(string s)
{
    int ans = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            ans++;
        }
    }
    return ans;
}

int left(string s)
{
    int ans = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            ans++;
        }
    }
    return ans;
}

// int maxScore(string s)
// {
//     int ans = INT_MIN;
//     int n = s.size();
//     for (int i = 1; i < n; i++)
//     {
//         ans = max(ans, (right(s.substr(i)) + left(s.substr(0, i))));
//     }
//     return ans;
// }

int maxScore(string s)
{
    int ones = 0;
    int zero = 0;
    int n = s.size();
    int ans = INT_MIN;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == '1')
        {
            ones++;
        }
        else
        {
            zero++;
        }
        ans = max(ans, zero - ones);
    }
    if (s[n - 1] == '1')
    {
        ones++;
    }
    return ans + ones;
}

int main()
{
    cout << maxScore("00111");

    return 0;
}