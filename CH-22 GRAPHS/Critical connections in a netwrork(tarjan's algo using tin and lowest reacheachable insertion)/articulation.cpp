/*Given an undirected graph with V vertices and E edges. The graph is represented as a 2D array edges[][], where each element edges[i] = [u, v] indicates an undirected edge between vertices u and v. Return all the articulation points (or cut vertices) in the graph. An articulation point is a vertex whose removal, along with all its connected edges, increases the number of connected components in the graph. 

The given graph may be disconnected, i.e., it may consist of more than one connected component. 
If no such point exists, return {-1}.
Examples :

Input: V = 5, edges[][] = [[0, 1], [1, 4], [4, 3], [4, 2], [2, 3]]

Output: [1, 4]
Explanation: Removing the vertex 1 or 4 will disconnects the graph as-
   
Input: V = 4, edges[][] = [[0, 1], [0, 2]]
Output: [0]
Explanation: Removing the vertex 0 will increase the number of disconnected components to 3.  
Constraints:
1 ≤ V, E ≤ 104*/

class Solution {
    private: 
        int timer = 1;
    private:
        void dfs(int node, int parent, vector<int> adj[], vector<int>& vis, int tin[], int low[], vector<int>& mark){
            vis[node] = 1;
            tin[node] = low[node] = timer;
            timer++;
            int child = 0;
            for(auto it : adj[node]){
                if(it == parent)continue;
                
                if(!vis[it]){
                    dfs(it, node, adj, vis, tin, low, mark);
                    low[node] = min(low[node], low[it]);
                if(low[it] >= tin[node] && parent != -1){
                    // >= condition as we wanna reach before node that could be destroyed in bridges we took only >
                    //parent != -1 becz in case of removal of a single starting point i.e. other nodes are connected to each other the connected components count will result to 1 only
                    mark[node] = 1;
                    //mark instead of vector: Used for avoiding duplicates as different neighbours may satisfy the above condition for art pt
                    }
                child++;
                }
                else{
                //Back-edge check
                low[node] = min(low[node], tin[it]);
                //Bcz we check to connected point not edge that is why we note the vertex of connection not the last node that could be vis by it as when destroyed we woudn't be able to reach
                }
            }
           if(child > 1 && parent == -1){
               mark[node] = 1;
           } 
        }
  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        
        
            for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            }
        
        
        vector<int> vis(V, 0);
        int tin[V];
        int low[V];
        vector<int> mark(V, 0);
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, -1, adj, vis, tin, low, mark);//-1 to work for separate components too
            }
        }
        
        vector<int> ans;
        
        for(int i = 0; i < V; i++){
            if(mark[i]){
                ans.push_back(i);
            }
        }
        if(!ans.size())return {-1};
        return ans;
    }
};