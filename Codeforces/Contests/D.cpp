#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string t, s;
        cin >> s >> t;
        int i = 0, j = 0;
        int n = s.size();
        int m = t.size();
        while (i < n && j < m)
        {
            if (s[i] == t[j])
            {
                j++;
            }
            else if (s[i] == '?')
            {
                s[i] = t[j];
                j++;
            }
            i++;
        }
        if (j < m)
        {
            cout << "NO\n";
            continue;
        }
        while (i < n)
        {
            if (s[i] == '?')
            {
                s[i] = 'a';
            }
            i++;
        }
        cout << "YES\n";
        cout << s << "\n";
    }
    return 0;
}