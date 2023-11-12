#include <bits/stdc++.h>
using namespace std;
void bfsTraversal(int j, vector<vector<int>> &adj, vector<int> &visited)
{
    queue<int> q;
    int start = j;
    visited[start] = 1;
    q.push(start);
    while (!q.empty())
    {
        int node = q.front();
        for (auto i : adj[node])
        {
            if (!visited[i])
                q.push(i), visited[i] = 1;
        }
        q.pop();
    }
}
int findNumOfProvinces(vector<vector<int>> &roads, int n)
{
    int ans = 0;
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans++;
            bfsTraversal(i, roads, visited);
        }
    }
    return ans;
}

int main()
{

    return 0;
}