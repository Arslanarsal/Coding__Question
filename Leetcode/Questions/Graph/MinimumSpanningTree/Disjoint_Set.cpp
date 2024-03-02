#include <bits/stdc++.h>
using namespace std;

class Disjoint_Set
{
private:
    vector<int> size;
    vector<int> rank;
    vector<int> parent;

public:
    Disjoint_Set(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findupar(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }

        return parent[node] = findupar(parent[node]);
    }

    void unionByRand(int u, int v)
    {
        int p_u = findupar(u);
        int p_v = findupar(v);

        if (p_u == p_v)
        {
            return;
        }
        if (rank[p_u] < rank[p_v])
        {
            parent[p_u] = p_v;
        }
        else if (rank[p_v] < rank[p_u])
        {
            parent[p_v] = p_u;
        }
        else
        {
            parent[p_v] = p_u;
            rank[p_u]++;
        }
        return;
    }

    void unionBySize(int u, int v)
    {
        int p_u = findupar(u);
        int p_v = findupar(v);

        if (p_u == p_v)
        {
            return;
        }
        if (size[p_u] < size[p_v])
        {
            parent[p_u] = p_v;
            size[p_v] += size[p_u];
        }
        else
        {
            parent[p_v] = p_u;
            size[p_u] += size[p_v];
        }
        return;
    }
};

int main()
{
    Disjoint_Set ds(7);
    // ds.unionByRand(1, 2);
    // ds.unionByRand(2, 3);
    // ds.unionByRand(4, 5);
    // ds.unionByRand(6, 7);
    // ds.unionByRand(5, 6);

    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    if (ds.findupar(3) == ds.findupar(4))
        cout << "Same\n";

    else
        cout << "Not Same\n";

    ds.unionByRand(3, 7);

    if (ds.findupar(3) == ds.findupar(4))
        cout << "Same\n";

    else
        cout << "Not Same\n";

    return 0;
}