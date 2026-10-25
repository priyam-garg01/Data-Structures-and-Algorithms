class Solution{
public:
    void bfs(int node, vector<int> adj[], vector<int>& inDeg, vector<int>& ans){
        queue<int> q;
        q.push(node);
        
    while(!q.empty()){
        node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto it : adj[node]){
            if(inDeg[it])inDeg[it]--;
            if(inDeg[it] == 0){
                q.push(it);
                }
            }
        }
    }
    vector<int> topoSort(int V, vector<int> adj[]){
        vector<int> inDeg(V, 0);//Marks the number of incoming edges of each node

        for(int i = 0; i < V; i++){
            for(auto it : adj[i]){
                inDeg[it]++;
            }
        }
        vector<int> ans;
        for(int i = 0; i < V; i++){
            if(inDeg[i] == 0){
                bfs(i, adj, inDeg, ans);
            }
        }
        
        return ans;
    }/*T.C. = O(V) + O(V) + O(V + E) = O(3V + E), S.C. = O(V) + O(V) = O(2V)*/
};