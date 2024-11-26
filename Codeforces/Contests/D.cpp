#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
const int INF = 1e9;  // Set a large value for infinity

// Dijkstra's Algorithm to find the shortest paths from a source node
vector<int> dijkstra(int start, int n, const vector<vector<pair<int, int>>>& graph) {
    vector<int> dist(n, INF);
    dist[start] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    fastio;
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<pair<int, int>>> graph(n);

        // Read in the graph
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;  // Convert to 0-based indexing
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        int ans = -1;
        double min_avg_dist = INF;

        // Run Dijkstra's from every node to calculate the maximum distance
        for (int i = 0; i < n; i++) {
            vector<int> dist = dijkstra(i, n, graph);

            // Calculate the average distance from node i to all other nodes
            double total_dist = 0;
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (dist[j] != INF) {  // If there is a path
                    total_dist += dist[j];
                    count++;
                }
            }
            
            double avg_dist = total_dist / count;

            // Find the node with the minimum average distance
            if (avg_dist < min_avg_dist) {
                min_avg_dist = avg_dist;
                ans = i + 1;  // 1-indexed node
            }
        }

        cout << ans << endl;
    }

    return 0;
}
