#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int time = 1;
    void dfs(int node, int parent, int tim[], int low[], int mark[], int vist[], vector<int> adj[])
    {
        vist[node] = 1;
        tim[node] = low[node] = time;
        time++;
        int child = 0;
        for (auto &&it : adj[node])
        {
            if (it == node)
            {
                continue;
            }
            if (!vist[it])
            {
                dfs(it, node, tim, low, mark, vist, adj);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tim[node] && parent != -1)
                {
                    mark[node] = 1;
                }
                child++;
            }
            else
            {
                low[node] = min(low[node], tim[it]);
            }
        }
        if (parent == -1 && child > 1)
        {
            mark[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int n, vector<int> adj[])
    {
        int low[n];
        int tim[n];
        int marks[n];
        memset(marks, 0, sizeof(marks)); // Correctly initialize the marks array
        int vist[n];
        memset(vist, 0, sizeof(vist)); // Initialize the visit array
        memset(tim, 0, sizeof(tim));   // Initialize the tim array
        memset(low, 0, sizeof(low));   // Initialize the low array

        // Perform DFS for each component
        for (int i = 0; i < n; i++)
        {
            if (!vist[i])
            {
                dfs(i, -1, tim, low, marks, vist, adj);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (marks[i] == 1)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}