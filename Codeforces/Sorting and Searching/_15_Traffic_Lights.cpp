#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define int long long
#define ld long double
const int mod = 1e9 + 7;
int t, n, m, q, x;

int32_t main()
{
    fastio;
    t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> x >> n;
        set<int> st;
        multiset<int> ans;
        ans.insert(x);
        st.insert(x);
        st.insert(0);
        for (int i = 0; i < n; i++)
        {
            cin >> m;
            st.insert(m);
            auto it = st.find(m);
            int left = *prev(it);
            int right = *next(it);
            ans.erase(ans.find(right - left));
            ans.insert(m - left);
            ans.insert(right - m);
            cout << *ans.rbegin() << " ";
        }
    }

    return 0;
}
