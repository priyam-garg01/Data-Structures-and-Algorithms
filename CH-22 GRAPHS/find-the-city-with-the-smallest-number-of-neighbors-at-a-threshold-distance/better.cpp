class Solution {
public:

    void dijkstra(int src, int n, vector<vector<int>>& adj, vector<int>& result){
        result[src] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, src});

        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(dist > result[node])continue;

            for(int adjNode = 0; adjNode < n; adjNode++){
                if(adj[node][adjNode] != 1e9){
                    if(result[node] + adj[node][adjNode] < result[adjNode]){
                        result[adjNode] = result[node] + adj[node][adjNode];
                        pq.push({result[adjNode], adjNode});
                    }
                }
             }
            }
        }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //Cities having the min number of edges connected to them within the distanceThreshold are to be returned if there are many such cities return the city with greater value number

        vector<vector<int>> cost(n, vector<int>(n, 1e9));

        for(auto it : edges){
            int node = it[0];
            int adjNode = it[1];
            int wt = it[2];
            cost[node][adjNode] = wt;
            cost[adjNode][node] = wt;
        }

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for(int i = 0; i < n; i++){
            dijkstra(i, n, cost, dist[i]);
        }

        //We have assigned wt to the cost matrix of every given entry

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[i][k] != 1e9 && dist[k][j] != 1e9){
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        //We get the shortest distance of every city from every other city

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][j] == 1e9){
                    dist[i][j] = -1;
                }
            }
        }
        int ctMin = n + 1;
        int city = -1;
        for(int i = 0; i < n; i++){
                int cities = 0;
            for(int j = 0; j < n; j++){
                if(i != j && dist[i][j] <= distanceThreshold){
                    cities++;
                    }
                }
                if(ctMin >= cities){
                    ctMin = cities;
                    city = i;
                }
            }
        return city;

        }
};/*Using dijkstra
T.C. = O(N*ELOG(N))*/