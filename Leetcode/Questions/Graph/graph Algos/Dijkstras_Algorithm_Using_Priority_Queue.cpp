#include <bits/stdc++.h>
using namespace std;

/*
--> Note: Two situations, where Dijkstra’s algorithm failed:
1. If the graph contains negative edges.
2. If the graph has a negative cycle (In this case Dijkstra’s algorithm fails to       minimize the distance, keeps on running, and goes into an infinite loop. As a result it gives TLE error).
*/
// TC  -->  E log (V);   (V Node and E edges)

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {

        // Create a priority queue for storing the nodes as a pair {dist,node}
        // where dist is the distance from source to the node.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Initialising distTo list with a large number to
        // indicate the nodes are unvisited initially.
        // This list contains distance from source to the nodes.
        vector<int> distTo(V, INT_MAX);

        // Source initialised with dist=0.
        distTo[S] = 0;
        pq.push({0, S});

        // Now, pop the minimum distance node first from the min-heap
        // and traverse for all its adjacent nodes.
        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            // Check for all adjacent nodes of the popped out
            // element whether the prev dist is larger than current or not.
            for (auto it : adj[node])
            {
                int v = it[0];
                int w = it[1];
                if (dis + w < distTo[v])
                {
                    distTo[v] = dis + w;

                    // If current distance is smaller,
                    // push it into the queue.
                    pq.push({dis + w, v});
                }
            }
        }
        // Return the list containing shortest distances
        // from source to all the nodes.
        return distTo;
    }
};

/*
O( V * ( pop vertex from min heap + no. of edges on each vertex * push in PQ ))

O( V * ( log(heapSize) + no. of edges * log(heapSize))

O( V * (log(heapSize) + V-1 * log(heapSize))    { one vertex can have V-1 edges }

O( V * (log(heapSize) * (V-1+1))

O( V * V * log(heapSize))

Now, at the worst case the heapSize will be equivalent to v² as if we consider pushing adjacent elements of a node, at the worst case each element will have V-1 nodes and they will be pushed onto the queue.

O( V * V * log(v²))

O ( v² * 2 log (V))

O ( E * 2 log(V))  { E= v², total number of edges}

O ( E * log(V))  Worst case Time Complexity of Dijkstra’s Algorithm.
*/

int main()
{
    // Driver code.
    int V = 3, E = 3, S = 2;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges;
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    int i = 0;
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);

    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}