#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        stack<int> st;
        long long ans = 0;
        int close = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == ')')
            {
                close++;
            }
        }
        close = (n / 2) - close;
        for (int i = 0; i < n; i++)
        {
            if (st.empty() || s[i] == '(')
            {
                st.push(i);
            }
            else if (s[i] == '_' && !close)
            {
                st.push(i);
            }
            else if (s[i] == '_' && close)
            {
                ans += (i - st.top());
                st.pop();
                close--;
            }
            else
            {
                ans += (i - st.top());
                st.pop();
            }
        }
        while (!st.empty())
        {
            int i = st.top();
            st.pop();
            int j = st.top();
            st.pop();
            ans += (i - j);
        }

        cout << ans << "\n";
    }

    return 0;
}
