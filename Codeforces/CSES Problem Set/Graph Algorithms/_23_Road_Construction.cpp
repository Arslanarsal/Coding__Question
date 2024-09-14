#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oSet; // [find_by_order ==> given address at index] |==| [order_of_key ==> Number of element smaller then X]y
#define int long long int
#define ld long double
const int mod = 1e9 + 7;
int t, n, q, m;

class dsu
{
    vector<int> parent, size;

public:
    dsu(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int get_p(int u)
    {
        if (parent[u] == u)
        {
            return u;
        }
        return parent[u] = get_p(parent[u]);
    }

    int get_size(int u)
    {
        return size[u];
    }

    void make_p(int u, int v)
    {
        u = get_p(u);
        v = get_p(v);
        if (u != v)
        {
            if (size[u] < size[v])
            {
                parent[u] = v;
                size[v] += size[u];
                size[u] = 0;
            }
            else
            {
                parent[v] = u;
                size[u] += size[v];
                size[v] = 0;
            }
        }
    }
};

int32_t main()
{
    fastio;
    t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> m;
        dsu ds(n);
        int largeComponent = 1, noOfComponent = n;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            if (ds.get_p(a) != ds.get_p(b))
            {
                ds.make_p(a, b);
                int c = ds.get_p(a);
                int temp = ds.get_size(c);
                largeComponent = max(largeComponent, temp);
                noOfComponent--;
            }
            cout << noOfComponent << " " << largeComponent << "\n";
        }
    }

    return 0;
}