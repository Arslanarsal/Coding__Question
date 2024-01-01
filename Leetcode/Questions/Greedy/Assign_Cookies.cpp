#include <bits/stdc++.h>
using namespace std;
int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0, j = 0;
    int ans = 0;
    while (j < s.size() && i < g.size())
    {
        if (s[j] >= g[i])
        {
            ans++;
            i++;
        }
        j++;
    }
    return ans;
}
int main()
{

    return 0;
}