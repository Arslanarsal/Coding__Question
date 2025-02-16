#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define int long long int
#define ld long double

const int mod = 1e9 + 7;
int t, n, q, l = 1;

vector<int> adj[500005]{};
int ans[500005]{};

struct node
{
    int fail, child[26] = {}, cnt = 0;
    vector<int> words;
} T[500005];

void insert(string &s, int i)
{
    int x = 1;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        int c = s[i] - 'a';
        if (!T[x].child[c])
            T[x].child[c] = ++l;
        x = T[x].child[c];
    }
    T[x].words.push_back(i);
}

void built_Aho()
{
    queue<int> q;

    T[1].fail = 1;
    for (int i = 0; i < 26; i++)
    {
        if (T[1].child[i])
            T[T[1].child[i]].fail = 1, q.push(T[1].child[i]);
        else
            T[1].child[i] = 1;
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int i = 0; i < 26; i++)
        {
            if (T[node].child[i])
                T[T[node].child[i]].fail = T[T[node].fail].child[i],
                q.push(T[node].child[i]);
            else
                T[node].child[i] = T[T[node].fail].child[i];
        }
    }
    for (int i = 2; i <= l; i++)
    {
        adj[T[i].fail].push_back(i);
    }
}

void run(string &s)
{
    int n = s.size();
    int x = 1;
    for (int i = 0; i < n; i++)
    {
        x = T[x].child[s[i] - 'a'];
        T[x].cnt++;
    }
}

int dfs(int i)
{
    int res = T[i].cnt;
    for (auto &&nei : adj[i])
        res += dfs(nei);
    for (auto &&w : T[i].words)
        ans[w] = res;
    return res;
}

int32_t main()
{
    fastio;
    memset(ans, 0, sizeof(ans));
    string s;
    cin >> s;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string j;
        cin >> j;
        insert(j, i);
    }
    built_Aho();
    run(s);
    dfs(1);
    for (int i = 0; i < t; i++)
        cout << ans[i] << "\n";

    return 0;
}
