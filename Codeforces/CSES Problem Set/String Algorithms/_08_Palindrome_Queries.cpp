#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll HASH = 257, MOD = 1e9 + 7;

int N, Q;
ll powH[200005] = {1};

namespace forward_hash
{
    ll T[400005];

    void update(int i, ll v)
    {
        for (T[i += N] = v; i > 1; i >>= 1)
            T[i >> 1] = (T[i] + T[i ^ 1]) % MOD;
    }

    ll query(int l, int r)
    {
        ll res = 0;
        for (l += N, r += N + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = (res + T[l++]) % MOD;
            if (r & 1)
                res = (res + T[--r]) % MOD;
        }
        return res;
    }
}

namespace backward_hash
{
    ll T[400005];

    void update(int i, ll v)
    {
        for (T[i += N] = v; i > 1; i >>= 1)
            T[i >> 1] = (T[i] + T[i ^ 1]) % MOD;
    }

    ll query(int l, int r)
    {
        ll res = 0;
        for (l += N, r += N + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = (res + T[l++]) % MOD;
            if (r & 1)
                res = (res + T[--r]) % MOD;
        }
        return res;
    }
}

int main()
{
    cin >> N >> Q;
    for (int i = 1; i < N; i++)
    {
        powH[i] = (powH[i - 1] * HASH) % MOD;
        // cout << powH[i] << " \n"[i == N - 1];
    }
    for (int i = 0; i < N; i++)
    {
        char c;
        cin >> c;
        forward_hash::update(i, powH[i] * (ll)c % MOD);
        backward_hash::update(i, powH[N - i - 1] * (ll)c % MOD);
    }

    while (Q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int k;
            char c;
            cin >> k >> c;
            k--;
            forward_hash::update(k, powH[k] * (ll)c % MOD);
            backward_hash::update(k, powH[N - k - 1] * (ll)c % MOD);
        }
        else if (t == 2)
        {
            int l, r;
            cin >> l >> r;
            l--, r--;
            ll forward = forward_hash::query(l, r);
            forward = (forward * powH[N - 1 - r]) % MOD;
            ll backward = backward_hash::query(l, r);
            backward = (backward * powH[l]) % MOD;
            if (forward == backward)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}

// #include <bits/stdc++.h>
// using namespace std;

// // Typedefs for simplicity
// using ll = long long;

// // Constants
// const ll HASH = 257, MOD = 1e9 + 7; 
// const int MAX_N = 200005;           

// 
// int N, Q;       
// ll powH[MAX_N]; 

// // Segment Tree Class
// class SegmentTree
// {
// private:
//     vector<ll> tree;
//     int size;

//     
//     void build(const vector<ll> &data, int node, int start, int end)
//     {
//         if (start == end)
//         {
//             tree[node] = data[start];
//         }
//         else
//         {
//             int mid = (start + end) / 2;
//             build(data, 2 * node + 1, start, mid);
//             build(data, 2 * node + 2, mid + 1, end);
//             tree[node] = (tree[2 * node + 1] + tree[2 * node + 2]) % MOD;
//         }
//     }

//    
//     void update(int node, int start, int end, int idx, ll value)
//     {
//         if (start == end)
//         {
//             tree[node] = value;
//         }
//         else
//         {
//             int mid = (start + end) / 2;
//             if (idx <= mid)
//             {
//                 update(2 * node + 1, start, mid, idx, value);
//             }
//             else
//             {
//                 update(2 * node + 2, mid + 1, end, idx, value);
//             }
//             tree[node] = (tree[2 * node + 1] + tree[2 * node + 2]) % MOD;
//         }
//     }

//     
//     ll query(int node, int start, int end, int l, int r)
//     {
//         if (r < start || end < l)
//         {
//             return 0; // Out of range
//         }
//         if (l <= start && end <= r)
//         {
//             return tree[node];
//         }
//         int mid = (start + end) / 2;
//         ll leftQuery = query(2 * node + 1, start, mid, l, r);
//         ll rightQuery = query(2 * node + 2, mid + 1, end, l, r);
//         return (leftQuery + rightQuery) % MOD;
//     }

// public:
//     SegmentTree(int n)
//     {
//         size = n;
//         tree.assign(4 * n, 0);
//     }

//     void build(const vector<ll> &data)
//     {
//         build(data, 0, 0, size - 1);
//     }

//     void update(int idx, ll value)
//     {
//         update(0, 0, size - 1, idx, value);
//     }

//     ll query(int l, int r)
//     {
//         return query(0, 0, size - 1, l, r);
//     }
// };

// int main()
// {
//     cin >> N >> Q;

//     // Precompute powers of HASH
//     powH[0] = 1;
//     for (int i = 1; i < N; i++)
//     {
//         powH[i] = (powH[i - 1] * HASH) % MOD;
//     }

//     // Initialize segment trees
//     SegmentTree forwardHash(N), backwardHash(N);

//     // Read initial string and build segment trees
//     vector<ll> forwardData(N), backwardData(N);
//     for (int i = 0; i < N; i++)
//     {
//         char c;
//         cin >> c;
//         forwardData[i] = (powH[i] * (ll)c) % MOD;
//         backwardData[i] = (powH[N - i - 1] * (ll)c) % MOD;
//     }
//     forwardHash.build(forwardData);
//     backwardHash.build(backwardData);

//     // Process queries
//     while (Q--)
//     {
//         int t;
//         cin >> t;

//         if (t == 1)
//         {
//             // Update query
//             int k;
//             char c;
//             cin >> k >> c;
//             k--;
//             forwardHash.update(k, (powH[k] * (ll)c) % MOD);
//             backwardHash.update(k, (powH[N - k - 1] * (ll)c) % MOD);
//         }
//         else if (t == 2)
//         {

//             int l, r;
//             cin >> l >> r;
//             l--, r--; // Convert to 0-based indices

//             ll forward = forwardHash.query(l, r);
//             forward = (forward * powH[N - 1 - r]) % MOD;

//             ll backward = backwardHash.query(l, r);
//             backward = (backward * powH[l]) % MOD;

//             if (forward == backward)
//             {
//                 cout << "YES\n";
//             }
//             else
//             {
//                 cout << "NO\n";
//             }
//         }
//     }

//     return 0;
// }
