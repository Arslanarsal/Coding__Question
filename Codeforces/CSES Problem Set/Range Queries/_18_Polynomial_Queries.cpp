#include <bits/stdc++.h>
using namespace std;

class SegmentTree // range set value, range query for sum segtree, can be easily modified for other things
{
private:
    int n;
    vector<long long> segtree;
    vector<pair<long long, int>> lazy;

public:
    void init(int sz)
    {
        n = sz;
        segtree.resize(1 + 4 * sz);
        lazy.resize(1 + 4 * sz);
    }
    long long gauss(int start, int len, int step)
    {
        return (start * len) + (step * (len - 1) * len / 2);
    }
    void lz(int node, int L, int R)
    {
        segtree[node] += gauss(lazy[node].first, R - L + 1, lazy[node].second);
        int mid = (L + R) / 2;
        if (L != R)
        {
            lazy[node << 1].first += lazy[node].first;
            lazy[node << 1].second += lazy[node].second;
            lazy[node << 1 | 1].first += lazy[node].first + 1LL * lazy[node].second * (mid - L + 1);
            lazy[node << 1 | 1].second += lazy[node].second;
        }
        lazy[node] = {0, 0};
    }
    void build(int node, int L, int R, vector<int> &v)
    {
        if (L == R)
        {
            segtree[node] = v[L];
            return;
        }
        int mid = (L + R) / 2;
        build(node << 1, L, mid, v);
        build(node << 1 | 1, mid + 1, R, v);
        segtree[node] = segtree[node << 1] + segtree[node << 1 | 1];
    }
    void update(int node, int L, int R, int Lq, int Rq, int val)
    {
        if (lazy[node].first)
            lz(node, L, R);
        if (R < Lq || L > Rq)
            return;
        if (Lq <= L && R <= Rq)
        {
            lazy[node].first = val + (L - Lq);
            lazy[node].second++;
            lz(node, L, R);
            return;
        }
        int mid = (L + R) / 2;
        update(node << 1, L, mid, Lq, Rq, val);
        update(node << 1 | 1, mid + 1, R, Lq, Rq, val);
        segtree[node] = segtree[node << 1] + segtree[node << 1 | 1];
    }
    long long query(int node, int L, int R, int Lq, int Rq)
    {
        if (lazy[node].first)
            lz(node, L, R);
        if (R < Lq || L > Rq)
            return 0;
        if (Lq <= L && R <= Rq)
            return segtree[node];
        int mid = (L + R) / 2;
        return query(node << 1, L, mid, Lq, Rq) + query(node << 1 | 1, mid + 1, R, Lq, Rq);
    }
};

SegmentTree st;
int main()
{
    int n, q;
    cin >> n >> q;

    st.init(n);

    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    st.build(1, 1, n, v);
    for (int i = 1; i <= q; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int L, R;
            cin >> L >> R;
            st.update(1, 1, n, L, R, 1);
        }
        if (t == 2)
        {
            int L, R;
            cin >> L >> R;
            cout << st.query(1, 1, n, L, R) << '\n';
        }
    }
    return 0;
}

// #include <bits/stdc++.h>
// #define range(it, a, b) for (ll it = a; it < b; it++)
// #define all(x) begin(x), end(x)
// #define ll long long
// #define ull unsigned long long
// #define INF64 ((ll)1 << 62)
// #define INF32 (1 << 30)
// #define mset multiset
// #define uset unordered_set
// #define umap unordered_map
// #define pqueue priority_queue
// #define ptr(A) shared_ptr<A>

// using namespace std;

// void setio(string name)
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     if (name.size())
//     {
//         freopen((name + ".in").c_str(), "r", stdin);
//         freopen((name + ".out").c_str(), "w", stdout);
//     }
// }

// struct SegTree
// {
//     struct Node
//     {
//         Node *left;
//         Node *right;
//         ll lazy, cnt = 0;
//         ll l, r, m, sum;
//         ll size() { return r - l + 1; }
//     };

//     Node *root;
//     vector<ll> &arr;

//     SegTree(vector<ll> &a) : arr(a)
//     {
//         root = new Node;
//         root->l = 0;
//         root->r = a.size() - 1;
//         root->m = root->r / 2;
//         build(root);
//     }

//     void build(Node *node)
//     {
//         if (node->l == node->r)
//         {
//             node->sum = arr[node->l];
//             return;
//         }

//         node->left = new Node;
//         node->left->l = node->l;
//         node->left->r = node->m;
//         node->left->m = (node->left->l + node->left->r) / 2;
//         build(node->left);

//         node->right = new Node;
//         node->right->l = node->m + 1;
//         node->right->r = node->r;
//         node->right->m = (node->right->l + node->right->r) / 2;
//         build(node->right);

//         node->sum = node->left->sum + node->right->sum;
//     }

//     ll f(ll n, ll k)
//     {
//         return (n * (n - 1)) / 2 + n * k;
//     }

//     void push(Node *node)
//     {
//         if (node->cnt)
//         {
//             ll k = node->lazy - (node->cnt * ((node->size() * (node->size() - 1)) / 2));
//             k /= node->size();

//             ll ans_l = node->cnt * (node->left->size() * (node->left->size() - 1) / 2) + k * node->left->size();
//             node->left->sum += ans_l;
//             node->left->lazy += ans_l;
//             node->left->cnt += node->cnt;

//             ll ans_r = node->lazy - ans_l;
//             node->right->sum += ans_r;
//             node->right->lazy += ans_r;
//             node->right->cnt += node->cnt;

//             node->lazy = 0;
//             node->cnt = 0;
//         }
//     }

//     void update(Node *node, ll l, ll r, ll from)
//     {
//         if (node->l == l && node->r == r)
//         {
//             node->sum += f(node->size(), from);
//             node->lazy += f(node->size(), from);
//             node->cnt++;
//             return;
//         }

//         push(node);
//         if (l <= node->m)
//             update(node->left, l, min(r, node->m), from);
//         if (node->m < r)
//             update(node->right, max(l, node->m + 1), r, from + (max(l, node->m + 1) - l));
//         node->sum = node->left->sum + node->right->sum;
//     }

//     void update(ll l, ll r) { update(root, l, r, 1); }

//     ll query(Node *node, ll l, ll r)
//     {
//         if (node->l == l && node->r == r)
//             return node->sum;

//         push(node);
//         ll ans = 0;
//         if (l <= node->m)
//             ans += query(node->left, l, min(r, node->m));
//         if (node->m < r)
//             ans += query(node->right, max(l, node->m + 1), r);
//         return ans;
//     }

//     ll query(ll l, ll r) { return query(root, l, r); }
// };

// ll n, q;
// vector<ll> arr;

// void solve()
// {
//     cin >> n >> q;
//     arr.resize(n);

//     range(i, 0, n)
//             cin >>
//         arr[i];
//     SegTree st(arr);

//     ll t, l, r;
//     while (q--)
//     {
//         cin >> t;
//         if (t == 1)
//         {
//             cin >> l >> r;
//             l--;
//             r--;
//             st.update(l, r);
//             continue;
//         }
//         cin >> l >> r;
//         l--;
//         r--;
//         cout << st.query(l, r) << '\n';
//     }
// }

// int main()
// {
//     setio("");
//     ll t = 1;
//     // cin >> t;
//     while (t--)
//         solve();
// }