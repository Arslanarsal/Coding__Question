#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        set<int> st;
        int a;
        for (int i = 0; i < m; i++)
        {
            cin >> a;
            st.insert(a);
        }
        string c;
        cin >> c;
        sort(c.begin(), c.end());
        int i = 0;
        for (auto &&it : st)
        {
            s[it-1] = c[i++];
        }
        cout << s << "\n";
    }

    return 0;
}