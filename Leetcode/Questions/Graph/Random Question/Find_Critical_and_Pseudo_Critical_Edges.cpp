#include <bits/stdc++.h>
using namespace std;

#include <vector>
#include <algorithm>

using namespace std;

class dsu
{
    vector<int> parent;
    vector<int> size;

public:
    dsu(int n)
    {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int get_p(int p)
    {
        if (parent[p] == p)
        {
            return p;
        }
        return parent[p] = get_p(parent[p]);
    }
    void make_p(int u, int v)
    {
        int pu = get_p(u);
        int pv = get_p(v);
        if (pu == pv)
        {
            return;
        }
        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu]; 
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv]; 
        }
    }
};

// Comparator function to sort edges based on weight
inline bool cmp(const vector<int> &a, const vector<int> &b)
{
    return a[2] < b[2]; 
}

class Solution
{
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
    {
        int m = edges.size(); // Bug: Initialize m to edges.size() instead of -edges.size()
        for (int i = 0; i < m; i++)
        {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), cmp); 

        dsu ds(n);
        int MST = 0;
        for (auto &it : edges)
        {
            int u = it[0], v = it[1], wt = it[2], idx = it[3];
            int pu = ds.get_p(u);
            int pv = ds.get_p(v);
            if (pu == pv)
            {
                continue;
            }
            MST += wt;
            ds.make_p(pu, pv);
        }

        vector<vector<int>> ans(2);
        for (int i = 0; i < m; i++)
        {
            dsu ds(n);
            int sum = 0;
            for (auto &it : edges)
            {
                int u = it[0], v = it[1], wt = it[2], idx = it[3];
                if (idx == i)
                {
                    continue;
                }
                int pu = ds.get_p(u);
                int pv = ds.get_p(v);
                if (pu == pv)
                {
                    continue;
                }
                sum += wt;
                ds.make_p(pu, pv);
            }
            if (sum > MST)
            {
                ans[0].push_back(i);
            }
            else
            {
                dsu ds(n);
                sum = 0;
                int u = edges[i][0], v = edges[i][1], wt = edges[i][2], idx = edges[i][3];
                ds.make_p(u, v);
                sum += wt;
                for (auto &it : edges)
                {
                    int u = it[0], v = it[1], wt = it[2], idx = it[3];
                    if (idx == i)
                    {
                        continue;
                    }
                    int pu = ds.get_p(u);
                    int pv = ds.get_p(v);
                    if (pu == pv)
                    {
                        continue;
                    }
                    sum += wt;
                    ds.make_p(pu, pv);
                }
                if (sum == MST)
                {
                    ans[1].push_back(i);
                }
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}