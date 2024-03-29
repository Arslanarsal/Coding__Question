#include <bits/stdc++.h>
using namespace std;
/*
    Time Complexity : O(N^2)
    Space Complexity : O(N)

    Where N is the number of cities.
*/

// void dfs(int p, int n, vector<vector<int>>& roads, vector<int>& visited) {
//     visited[p] = 1; // Mark the current city 'p' as visited.

//     // Traverse all cities to find the ones connected to city 'p'.
//     for (int i = 0; i < n; i++) {
//         if (roads[p][i] && !visited[i]) {

//             // If city 'i' is connected to 'p' and not visited yet, perform DFS on city 'i'.
//             dfs(i, n, roads, visited);
//         }
//     }
// }

// int findNumOfProvinces(vector<vector<int>>& roads, int n) {
//     vector<int> visited(n, 0); // Create an array to track visited cities, initialized to 0.
//     int count = 0; // Initialize the province count.

//     // Traverse all cities to find unvisited cities and perform DFS on them.
//     for (int i = 0; i < n; i++) {
//         if (!visited[i]) {

//             // If city 'i' is unvisited, then it's part of a new province.
//             // Perform DFS to mark all connected cities in this province as visited.
//             dfs(i, n, roads, visited);

//             // Increment the province count after DFS traversal.
//             count++;
//         }
//     }

//     // Return the total number of provinces.
//     return count;
// }

class Solution
{
    void dfs(int i, vector<int> &vis, vector<int> adj[])
    {
        vis[i] = true;

        for (auto &&j : adj[i])
        {
            if (!vis[j])
            {
                dfs(j, vis, adj);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> adj[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && isConnected[i][j])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                ans++;
                dfs(i, vis, adj);
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}