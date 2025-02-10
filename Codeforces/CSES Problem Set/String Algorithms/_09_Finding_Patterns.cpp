#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false), cin.tie(nullptr);

// Ordered set
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int N = 5e5 + 7;
vector<int> leaf[N], adj[N], seen(N), ans(N);

class AhoCorasick
{
    struct Node
    {
        int next[26], end = 0, link = -1, cnt = 0;
        Node() { memset(next, -1, sizeof(next)); }
    };

<<<<<<< HEAD
void insert(string s, int i)
{
    int x = 1;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (T[x].ch[s[i] - 'a'] == 0)
            T[x].ch[s[i] - 'a'] = ++I;

        x = T[x].ch[s[i] - 'a'];
    }
    T[x].word.PB(i);
}
=======
    vector<Node> trie = {Node()};
>>>>>>> b0804715d72f38150b229af1738b5cf93b238eca

    void add(const string &s, int idx)
    {
        int v = 0;
        for (char ch : s)
        {
            int c = ch - 'a';
            if (trie[v].next[c] == -1)
            {
                trie[v].next[c] = trie.size();
                trie.emplace_back();
            }
            v = trie[v].next[c];
        }
        trie[v].end++;
        leaf[v].push_back(idx);
    }

    void build()
    {
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < 26; i++)
            {
                int v = trie[u].next[i];
                if (v != -1)
                {
                    int cur = trie[u].link;
                    while (cur != -1 && trie[cur].next[i] == -1)
                        cur = trie[cur].link;
                    trie[v].link = (cur == -1 ? 0 : trie[cur].next[i]);
                    trie[v].cnt += trie[trie[v].link].cnt;
                    q.push(v);
                }
            }
        }
        for (int i = 1; i < trie.size(); i++)
            adj[trie[i].link].push_back(i);
    }

public:
    AhoCorasick(vector<string> &patterns)
    {
        for (int i = 0; i < patterns.size(); i++)
            add(patterns[i], i);
        build();
    }

    void search(const string &s)
    {
        int v = 0;
        for (char ch : s)
        {
            int c = ch - 'a';
            while (v != -1 && trie[v].next[c] == -1)
                v = trie[v].link;
            v = (v == -1 ? 0 : trie[v].next[c]);
            seen[v]++;
        }
    }

    void dfs(int u = 0)
    {
        for (int v : adj[u])
        {
            seen[v] += seen[u];
            dfs(v);
        }
        for (int idx : leaf[u])
            ans[idx] = seen[u];
    }
};

void solve()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> patterns(n);
    for (string &p : patterns)
        cin >> p;

    AhoCorasick aho(patterns);
    aho.search(s);
    aho.dfs();

    for (int i = 0; i < n; i++)
        cout << (ans[i] ? "YES" : "NO") << "\n";
}

int main()
{
    fast_io;
    solve();
    return 0;
}

// #include <iostream>
// #include <algorithm>
// #include <queue>
// using namespace std;

// #define PB push_back

// string S;
// int K, I = 1, ans[500005];

// vector<int> adj[500005];

// struct node
// {
//     int fail, ch[26] = {}, cnt = 0;
//     vector<int> word;
// } T[500005];

// void insert(string s, int i)
// {
//     int x = 1;
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (T[x].ch[s[i] - 'a'] == 0)
//             T[x].ch[s[i] - 'a'] = ++I;
//         x = T[x].ch[s[i] - 'a'];
//     }
//     T[x].word.PB(i);
// }

// void build()
// {
//     queue<int> Q;
//     int x = 1;
//     T[1].fail = 1;
//     for (int i = 0; i < 26; i++)
//     {
//         if (T[x].ch[i])
//             T[T[x].ch[i]].fail = x, Q.push(T[x].ch[i]);
//         else
//             T[x].ch[i] = 1;
//     }
//     while (!Q.empty())
//     {
//         x = Q.front();
//         Q.pop();
//         for (int i = 0; i < 26; i++)
//         {
//             if (T[x].ch[i])
//                 T[T[x].ch[i]].fail = T[T[x].fail].ch[i], Q.push(T[x].ch[i]);
//             else
//                 T[x].ch[i] = T[T[x].fail].ch[i];
//         }
//     }
//     for (int i = 2; i <= I; i++)
//         adj[T[i].fail].PB(i);
// }

// void run(string s)
// {
//     for (int i = 0, x = 1; i < s.size(); i++)
//     {
//         x = T[x].ch[s[i] - 'a'];
//         T[x].cnt++;
//     }
// }

// int dfs(int u)
// {
//     int res = T[u].cnt;
//     for (int v : adj[u])
//         res += dfs(v);
//     for (int w : T[u].word)
//         ans[w] = res;
//     return res;
// }

// int main()
// {

//     cin >> S >> K;
//     for (int i = 0; i < K; i++)
//     {
//         string s;
//         cin >> s;
//         insert(s, i);
//     }

//     build();
//     run(S);
//     dfs(1);

//     for (int i = 0; i < K; i++)
//         cout << (ans[i] ? "YES" : "NO") << '\n';
// }