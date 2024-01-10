#include <bits/stdc++.h>
using namespace std;

/*
Dijkstra’s Shortest Path algorithm and Bellman-Ford algorithm are single-source shortest path algorithms where we are given a single source node and are asked to find out the shortest path to every other node from that given source. But in the Floyd Warshall algorithm, we need to figure out the shortest distance from each node to every other node.

Basically, the Floyd Warshall algorithm is a multi-source shortest path algorithm and it helps to detect negative cycles as well. The shortest path between node u and v necessarily means the path(from u to v) for which the sum of the edge weights is minimum.
*/

/*
    Time complexity: O(N^3)
    Space complexity: O(N^2)

    where 'N' is the number of vertices in the graph.
*/

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, 1e9));
    for (int i = 0; i < m; i++)
    {
        matrix[edges[i][0]][edges[i][1]] = edges[i][2];
    }
    for (int i = 1; i < n + 1; i++)
    {
        matrix[i][i] = 0;
    }

    for (int v = 1; v <= n; v++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (matrix[i][v] != 1e9 && matrix[v][j] != 1e9)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][v] + matrix[v][j]);
                }
            }
        }
    }
    return matrix[src][dest];
}

int main()
{

    return 0;
}