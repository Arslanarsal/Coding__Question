#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> size;
    vector<int> parent;

public:
    DSU(int n)
    {
        size.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int get_p(int i)
    {
        if (parent[i] == i)
        {
            return i;
        }
        return parent[i] = get_p(parent[i]);
    }
    void make_p(int a, int b)
    {
        int a_p = get_p(a);
        int b_p = get_p(b);

        if (size[a_p] < size[b_p])
        {
            parent[a_p] = b_p;
            size[b_p] += size[a_p];
        }
        else
        {
            parent[b_p] = a_p;
            size[a_p] += size[b_p];
        }
    }
};

class Solution
{
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[0] > b[0];
    }

public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        sort(edges.begin(), edges.end(), cmp);
        DSU alic(n + 1), bob(n + 1);
        int m = edges.size();
        int temp = 0;

        for (int i = 0; i < m; i++)
        {
            int type = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];
            if (type == 3)
            {
                bool flage = false;
                int u_p = alic.get_p(u);
                int v_p = alic.get_p(v);
                if (u_p != v_p)
                {
                    alic.make_p(u, v);
                }
                else
                {
                    flage = true;
                }

                u_p = bob.get_p(u);
                v_p = bob.get_p(v);
                if (u_p != v_p)
                {
                    bob.make_p(u, v);
                }
                else
                {
                    flage = true;
                }
                temp += flage;
            }
            else if (type == 2)
            {
                int u_p = bob.get_p(u);
                int v_p = bob.get_p(v);
                if (u_p != v_p)
                {
                    bob.make_p(u, v);
                }
                else
                {
                    temp++;
                }
            }
            else
            {
                int u_p = alic.get_p(u);
                int v_p = alic.get_p(v);
                if (u_p != v_p)
                {
                    alic.make_p(u, v);
                }
                else
                {
                    temp++;
                }
            }
        }
        int x = alic.get_p(1);
        int y = bob.get_p(1);
        for (int i = 2; i <= n; i++)
        {
            int x1 = alic.get_p(i);
            int y1 = bob.get_p(i);
            if (x != x1 || y != y1)
            {
                return -1;
            }
        }
        return m - temp;
    }
};

int main()
{

    return 0;
}