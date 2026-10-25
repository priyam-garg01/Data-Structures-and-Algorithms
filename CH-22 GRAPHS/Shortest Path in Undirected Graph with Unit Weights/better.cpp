class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M){
        //since it is an undirected graph we cannot use the topo sort approach
        // make adj List
        vector<vector<int>> adj(N);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        queue<int> q;
        int src = 0;
        q.push({src, 0});
        vector<int> dist(N, INT_MAX);
        dist[src] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : adj[node]){
                if(dist[it] > dist[node] + 1){
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
        for(int i = 0; i < N; i++){
            if(dist[[i] == INT_MAX]){
                dist[i] = -1;
            }
        }

        return dist;
    }
};