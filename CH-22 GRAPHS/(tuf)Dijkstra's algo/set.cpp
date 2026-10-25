class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        //We have created an adj List with vector of pairs
        
        // now we use a bfs traversal to get the distance arr
        
//We know that set stores a single copy of the item in an ascending order
        set<pair<int, int>> st;;//Stores the dist and the node val
        st.insert({0, src});
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        while(!st.empty()){
            auto it = *(st.begin());
            int len = it.first;
            int node = it.second;
            st.erase(it);
            
            for(auto it : adj[node]){
                int edgeWt = it.second;
                int adjNode = it.first;
                if(dist[adjNode] > edgeWt + len){
                    //if the dist existed before
                    if(dist[adjNode] != INT_MAX){
                        st.erase({dist[adjNode], adjNode});
                    }
                    //This doesnot affect the T.C. by much as we replace fewer iterations by a logn(n)
                    //so it is totally dependent on the graph given
                    
                    dist[adjNode] = edgeWt + len;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};