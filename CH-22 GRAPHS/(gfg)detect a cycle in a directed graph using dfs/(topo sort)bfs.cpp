class Solution{
public:
    void bfs(int node, vector<int> adj[], vector<int>& inDeg, vector<int>& ans){
        //Topologiacl Sort: Applied only on Directed acyclic graph

        queue<int> q;
        q.push(node);

        while(!q.empty()){
            node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]){
                if(inDeg[it])inDeg[it]--;
                if(inDeg[it] == 0)q.push(it);
            }
        }
    }
    bool isCyclic(int N, vector<int> adj[]) {
        vector<int> inDeg(N, 0);
//Notes the inDeg of every node
        for(int i = 0; i < N; i++){
            for(auto it : adj[i]){
                inDeg[it]++;
            }
        }
        // finds the node with inDeg = zero
        int zDeg = -1;
        vector<int> ans;
        for(int i = 0; i < N; i++){
            if(inDeg[i] == 0){
                zDeg = i;
                bfs(zDeg, adj, inDeg, ans);
            }
        }
        if(zDeg == -1)return false;
       
        //If the vector ans has size n we observe the the directed graph is acyclic else it is cyclic as the q already gets emptied before all elements are inserted as in linear directed graph the inDeg are alligned accordingly

        if(ans.size() != inDeg.size())return true;
        return false;
    }
};