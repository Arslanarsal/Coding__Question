#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent, size;

public:
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int p)
    {
        if (parent[p] == p)
        {
            return p;
        }
        return parent[p] = find(parent[p]);
    }

    void make_p(int u, int v)
    {
        int pv = find(v);
        int pu = find(u);
        if (pv != pu)
        {
            if (size[pv] < size[pu])
            {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
            else
            {
                parent[pu] = pv;
                size[pv] += size[pu];
            }
        }
    }
};

class Solution
{
public:
    int regionsBySlashes(vector<string> &grid)
    {

        int n = grid.size();
        DSU ds(n * n * 4);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                char c = grid[i][j];
                int index = 4 * (i * n + j);
                if (c == '/')
                {

                    ds.make_p(index, index + 1);
                    ds.make_p(index + 2, index + 3);
                }
                else if (c == '\\')
                {
                    int index = 4 * (i * n + j);
                    ds.make_p(index, index + 2);
                    ds.make_p(index + 1, index + 3);
                }
                else
                {
                    ds.make_p(index, index + 1);
                    ds.make_p(index, index + 2);
                    ds.make_p(index, index + 3);
                }

                if (i < n - 1)
                {
                    int index1 = 4 * ((i + 1) * n + j);
                    ds.make_p(index + 3, index1);
                }
                if (j < n - 1)
                {
                    int index1 = 4 * (i * n + (j + 1));
                    ds.make_p(index + 2, index1 + 1);
                }
            }
        }

        unordered_set<int> ans;

        for (int i = 0; i < (n * n * 4); i++)
        {
            int p = ds.find(i);
            ans.insert(p);
        }
        return ans.size();
    }
};

int main()
{

    return 0;
}