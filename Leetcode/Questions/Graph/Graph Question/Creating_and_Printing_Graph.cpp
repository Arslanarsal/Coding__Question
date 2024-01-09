#include <bits/stdc++.h>
using namespace std;

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
        // adjacencyList[i].push_back(i);

        for (int j = 0; j < graph[i].size(); j++)
        {
            adjacencyList[i].push_back(graph[i][j]);
        }
    }

    return adjacencyList;
}



int main()
{
    vector<vector<int>> edge = {{2, 1}, {2, 0}};
    vector<vector<int>> ans = printAdjacency(3, 2, edge);

    for (auto &&i : ans)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

   
    


    return 0;
}