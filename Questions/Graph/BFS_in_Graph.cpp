#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
    queue<int> q;
    vector<int> visited(n, 0);
    vector<int> BSF;
    int start = 0;
    visited[start] = 1;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        BSF.push_back(node);
        q.pop();

        for (int i = 0; i < n; ++i)
        {
            if (adj[node][i] && !visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    return BSF;
}
int main()
{

    // Adjacency list representation of the graph
    vector<vector<int>> adj = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {1, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
    };
    vector<int> ans = bfsTraversal(7, adj);
    cout << "Breadth First Search Traversal\n";
    for (auto x : ans)
        cout << x << " ";

    return 0;
}
