#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printAdjacenc(int n, int m, vector<vector<int>> &edges)
{
    vector<vector<int>> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i].push_back(i);
    }

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        ans[u].push_back(edges[i][1]);

        int v = edges[i][1];
        ans[v].push_back(edges[i][0]);
    }
    return ans;




    // vector<vector<int>> ans(n + 1, vector<int>(n + 1, 0));

    // for (int i = 0; i < m; i++)
    // {
    //     int u = edges[i][0];
    //     int v = edges[i][1];
    //     ans[u][v] = 1;
    //     ans[v][u] = 1;
    // }
    // return ans;
}

/*
    Time Complexity : O(N + M)
    Space Complexity : O(N + M)

    Where 'N' and 'M' denote the number of nodes and the number of edges in the graph.
*/

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
{

    vector<int> graph[n];

    // Creating the graph.
    for (int i = 0; i < edges.size(); i++)
    {

        // Adding adjecent nodes.
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    // Create an adjacency list of size 'N'.
    vector<vector<int>> adjacencyList(n);

    for (int i = 0; i < n; i++)
    {
        adjacencyList[i].push_back(i);

        for (int j = 0; j < graph[i].size(); j++)
        {
            adjacencyList[i].push_back(graph[i][j]);
        }
    }

    return adjacencyList;
}
int main()
{
    // vector<vector<int>> edge = {{2, 1}, {2, 0}};
    // vector<vector<int>> ans = printAdjacency(3, 2, edge);

    // for (auto &&i : ans)
    // {
    //     for (auto &&j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

   
    


    return 0;
}