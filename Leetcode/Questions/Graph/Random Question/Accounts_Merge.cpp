#include <bits/stdc++.h>
using namespace std;

class Dis_join
{
public:
    vector<int> parent;
    Dis_join(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int getparent(int vi)
    {
        if (parent[vi] == vi)
        {
            return vi;
        }
        return parent[vi] = getparent(parent[vi]);
    }

    void makeparent(int ui, int vi)
    {
        int root_u = getparent(ui);
        int root_v = getparent(vi);
        if (root_u != root_v)
        {
            parent[root_u] = root_v;
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        Dis_join dj(n);
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            int m = accounts[i].size();
            for (int j = 1; j < m; j++)
            {
                if (mp.count(accounts[i][j]))
                {
                    dj.makeparent(i, mp[accounts[i][j]]);
                }
                else
                {
                    mp[accounts[i][j]] = i;
                }
            }
        }
        vector<vector<string>> temp(n);
        for (auto &&i : mp)
        {
            temp[dj.getparent(i.second)].push_back(i.first);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (temp[i].size() > 0)
            {
                sort(temp[i].begin(), temp[i].end());
                temp[i].insert(temp[i].begin(), accounts[i][0]);
                ans.push_back(temp[i]);
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}