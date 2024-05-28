#include <bits/stdc++.h>
using namespace std;
class Solution
{
    void dfs(int node, int vist[], stack<int> &st, vector<vector<int>> &adj)
    {
        vist[node] = 1;
        for (auto &&it : adj[node])
        {
            if (!vist[it])
            {
                dfs(it, vist, st, adj);
            }
        }
        st.push(node);
    }
    void dfse(int node, int vist[], vector<vector<int>> &adj)
    {
        vist[node] = 1;
        for (auto &&it : adj[node])
        {
            if (!vist[it])
            {
                dfse(it, vist, adj);
            }
        }
    }

public:
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        stack<int> st;
        int vist[V];
        memset(vist, 0, sizeof(vist));
        for (int i = 0; i < V; i++)
        {
            if (!vist[i])
            {
                dfs(i, vist, st, adj);
            }
        }
        vector<vector<int>> rev(V);
        for (int i = 0; i < adj.size(); i++)
        {
            for (auto &&it : adj[i])
            {
                rev[it].push_back(i);
            }
        }
        int ans = 0;
        int arr[V];
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < V; i++)
        {
            int node = st.top();
            st.pop();
            if (!arr[node])
            {
                ans++;
                dfse(node, arr, rev);
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}