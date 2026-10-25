class Solution {
public:
// Wrong approach
/*The Issue: Multiple Independent Queues 🔄
In your code, you are calling bfs inside a loop for each node that has inDeg[i] == 0:

1for(int i = 0; i < n; i++){
2    if(inDeg[i] == 0){
3        bfs(i, adj, inDeg, ans); // This creates a brand new queue every time!
4    }
5}
Because each call to bfs creates its own local queue, the nodes don't share the same search space. If a node has multiple incoming edges from different starting nodes, its in-degree won't be decremented correctly in a coordinated way, and some safe nodes will get missed.*/
    void bfs(int node, vector<vector<int>>& adj, vector<int>& inDeg, vector<int>& ans){
        queue<int> q;
        q.push(node);

        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto it : adj[node]){
                if(inDeg[it])inDeg[it]--;
                if(inDeg[it] == 0)q.push(it);
            }
        }
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){
        //We are given the adjList
        //We need to find out the nodes which have no chance of being stuck in a loop

        //First we reverse the edges direction then we find the indeg from that list
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> inDeg(n, 0);
        for(int i = 0; i < n; i++){
            for(auto it : graph[i]){
                adj[it].push_back(i);
                inDeg[i]++;
            }
        }

        //Nodes which have outdeg zero will definitely be in our ans vector for other nodes we can use the detect cycle
        //So we iterate from them by reversing the order of adj list
        vector<int> ans;
    
        for(int i = 0; i < n; i++){
            if(inDeg[i] == 0){
                bfs(i, adj, inDeg, ans);
            }
        }
         sort(ans.begin(), ans.end());
        return ans;
    }
};
class Solution {
public:

    void bfs(vector<vector<int>>& adj, vector<int>& inDeg,queue<int>& q, vector<int>& ans){

        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto it : adj[node]){
                if(inDeg[it])inDeg[it]--;
                if(inDeg[it] == 0)q.push(it);
            }
        }
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){
        //We are given the adjList
        //We need to find out the nodes which have no chance of being stuck in a loop

        //First we reverse the edges direction then we find the indeg from that list
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> inDeg(n, 0);
        for(int i = 0; i < n; i++){
            for(auto it : graph[i]){
                adj[it].push_back(i);
                inDeg[i]++;
            }
        }

        //Nodes which have outdeg zero will definitely be in our ans vector for other nodes we can use the detect cycle
        //So we iterate from them by reversing the order of adj list
        vector<int> ans;
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(inDeg[i] == 0){
                q.push(i);
            }
        }
         bfs(adj, inDeg, q, ans);
         sort(ans.begin(), ans.end());
        return ans;
    }
};