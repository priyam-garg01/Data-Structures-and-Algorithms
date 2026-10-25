#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
  public:
    void dijkstra(int src, int n, vector<vector<int>>& adj, vector<int>& result) {
        // Priority queue stores {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        result[src] = 0;
        pq.push({0, src});
        
        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            // If we found a shorter path to u already, skip this stale entry
            if (d > result[u]) continue;
            
            for (int v = 0; v < n; v++) {
                // If there is an edge from u to v
                if (adj[u][v] != 1e8) {
                    if (result[u] + adj[u][v] < result[v]) {
                        result[v] = result[u] + adj[u][v];
                        pq.push({result[v], v});
                    }
                }
            }
        }
    }

    void floydWarshall(vector<vector<int>>& dist) {
        int n = dist.size();
        
        // We will store the final results in a temporary matrix first
        vector<vector<int>> final_dist(n, vector<int>(n, 1e8));
        
        // Run Dijkstra from every node as the source
        for (int i = 0; i < n; i++) {
            dijkstra(i, n, dist, final_dist[i]);
        }
        
        // Copy the results back to the original matrix
        dist = final_dist;
    }
};