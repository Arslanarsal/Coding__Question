#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    // Function to check for a cycle starting from a given node.
    bool checkForCycle(int s, int V, vector<int> adj[], vector<int> &visited)
    {

        // Store parent nodes to identify back edges.
        vector<int> parent(V, -1);

        // Queue to perform BFS traversal.
        queue<pair<int, int>> q;

        // Mark the current node as visited.
        visited[s] = true;

        // Push the current node into the queue with no parent.
        q.push({s, -1});

        while (!q.empty())
        {

            // Get the current node.
            int node = q.front().first;

            // Get its parent.
            int par = q.front().second;
            q.pop();

            // Traverse through the adjacent nodes of the current node.
            for (auto it : adj[node])
            {
                if (!visited[it])
                {

                    // Mark the adjacent node as visited.
                    visited[it] = true;

                    // Push it into the queue with the current node as parent.
                    q.push({it, node});
                }
                else if (par != it)
                {

                    // If the adjacent node is visited and not the parent, cycle is detected.
                    return true;
                }
            }
        }

        // If no cycle is detected.
        return false;
    }

public:
    // Function to detect a cycle in the graph.
    bool detectCycle(int V, vector<int> adj[])
    {

        // Create a vector to track visited nodes.
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {

            // If the current node is not visited.
            if (!vis[i])
            {

                // Check for cycle starting from this node.
                if (checkForCycle(i, V, adj, vis))
                    return true;
            }
        }

        // If no cycle is found in the entire graph.
        return false;
    }
};

int main()
{

    return 0;
}
