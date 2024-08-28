#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl ("\n")
#define int long long
#define pb push_back
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define mod 1000000007

// oset<int>s:s.find_by_order(k):Kth element in "s",s.order_of_key(k):Number of item strictly lessthan k
template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// Syntax to create a min heap for priority queue
// priority_queue <int, vector<int>, greater<int>>pq;

int triee[1000005][26];
int endnode[1000005];
int counter = 0;
int dp[5001];

void insert(string s)
{
    int curr = 0;

    for (auto i : s)
    {
        if (triee[curr][i - 'a'] == 0)
            triee[curr][i - 'a'] = ++counter;
        curr = triee[curr][i - 'a'];
    }
    endnode[curr] = 1;
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
    {
        string s;
        cin >> s;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            string x;
            cin >> x;
            insert(x);
        }

        int m = s.length();
        dp[m] = 1;

        for (int i = m - 1; i >= 0; i--)
        {
            int curr = 0, ans = 0;
            for (int j = i; j < m; j++)
            {
                if (triee[curr][s[j] - 'a'] == 0)
                    break;

                curr = triee[curr][s[j] - 'a'];
                if (endnode[curr])
                {
                    ans = (ans + dp[j + 1] % mod) % mod;
                }
            }
            dp[i] = ans;
        }

        cout << dp[0] << endl;
    }
    return 0;
}