#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;

string manacher()
{
    string t = "#";
    for (auto &&ch : s)
    {
        t += ch;
        t += "#";
    }
    int n = t.size();
    vector<int> b(n, 1);
    int maxlen = 0, idx = 0;
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i < r)
        {
            b[i] = max(0LL, min(r - i, b[l + r - i]));
        }
        while (i + b[i] < n && i - b[i] >= 0 && t[b[i] + i] == t[i - b[i]])
        {
            b[i]++;
        }
        b[i]--;
        if (b[i] + i > r)
        {
            r = b[i] + i;
            l = i - b[i];
        }
        if (b[i] > maxlen)
        {
            maxlen = b[i];
            idx = i / 2;
        }
    }
    string ans = s.substr(idx - (maxlen / 2), maxlen);
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    cout << manacher() << "\n";
    return 0;
}