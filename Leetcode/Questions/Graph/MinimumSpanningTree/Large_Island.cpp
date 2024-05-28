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
    int find(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        return parent[node] = find(parent[node]);
    }

    int nodesize(int i)
    {
        if (i < 0 || i >= size.size())
        {
            return 0;
        }
        return size[i];
    }

    void unionByRank(int u, int v)
    {
        int p_u = find(u);
        int p_v = find(v);

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
    }

    void unionBySize(int u, int v)
    {
        int p_u = find(u);
        int p_v = find(v);

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
    }
};

class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        Disjoint_Set ds(n * m);
        int arrx[4] = {-1, 0, 1, 0};
        int arry[4] = {0, 1, 0, -1};

        // Perform union operations on initial 1s
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    int node = (m * i) + j;
                    for (int k = 0; k < 4; k++)
                    {
                        int x = i + arrx[k];
                        int y = j + arry[k];
                        if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1)
                        {
                            int newnode = (m * x) + y;
                            ds.unionBySize(node, newnode);
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    set<int> s;
                    for (int k = 0; k < 4; k++)
                    {
                        int x = i + arrx[k];
                        int y = j + arry[k];
                        if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1)
                        {
                            int newnode = (m * x) + y;
                            s.insert(ds.find(newnode));
                        }
                    }

                    int temp = 1;
                    for (auto &&root : s)
                    {
                        temp += ds.nodesize(root);
                    }
                    ans = max(ans, temp);
                }
            }
        }
        return ans == 0 ? n * m : ans;
    }
};

int main()
{

    return 0;
}