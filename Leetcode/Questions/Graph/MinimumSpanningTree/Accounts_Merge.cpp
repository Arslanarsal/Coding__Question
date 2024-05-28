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

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        Disjoint_Set ds(n);
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if (!(mp.count(mail)))
                {
                    mp[mail] = i;
                }
                else
                {
                    ds.unionByRand(i, mp[mail]);
                }
            }
        }
        vector<string> mergedmail[n];
        for (auto &&it : mp)
        {
            string mail = it.first;
            int p = ds.findupar(it.second);
            mergedmail[p].push_back(mail);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (mergedmail[i].size() == 0)
            {
                continue;
            }
            sort(mergedmail[i].begin(), mergedmail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto &&j : mergedmail[i])
            {
                temp.push_back(j);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main()
{

    return 0;
}