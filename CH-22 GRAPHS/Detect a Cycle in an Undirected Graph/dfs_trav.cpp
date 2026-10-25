class Solution{
public:
    bool detectCycle(int src, int parent, vector<int> adj[], vector<int>& vis){
        if(vis[src]){
            return true;
        }
        vis[src] = 1;

        for(auto it : adj[src]){
            if(!vis[it]){
               if(detectCycle(it, src, adj, vis)) return true;   
            }
            else if(it != parent)return true;
        }

        return false;//At last if none of the above is returned
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(detectCycle(i, -1, adj, vis)) return true;
            }
        }
        return false;
    }
};
//T.C. = O(N + 2E) + O(N), S.C. = O(2N)
//M-2 We can also use a detect variable passed by ref to void function detect cycle
