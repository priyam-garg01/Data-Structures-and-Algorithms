class Solution {
public:
    bool dfs(int src, int group, vector<vector<int>>& graph, vector<int>& vis){
        vis[src] = group;
        
            for(auto it : graph[src]){
                if(vis[it] == -1){
                    // if(vis[node] == 1){
                    //     vis[it] = 0;
                    // }
                    // else{
                    //     vis[it] = 1;
                    // }
                    /* return dfs(it, !vis[src, graph, vis]);
                    This is wrong as true is only returned after checking every adj node*/
                    if(dfs(it, !vis[src], graph, vis) == false)return false;
                }
                else if(vis[it] == vis[src]){
                    return false;
                }
            }
            return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
       /*Bipartite graph: Every adjacent node has different color, means every node can be separated in two set be it colors, node types, etc.*/
       /*Results:
       1)Every even cycle graph and every linear graph is bipartite 
       2)Every odd cycle graph is not bipartite*/
       //So we need to check is the graph has an odd cycle if yes then return false else return true
        int m = graph.size();
        int n = graph[0].size();
        vector<int> vis(m, -1);

        for(int i = 0; i < m; i++){
            if(vis[i] == -1){
            if(dfs(i, 1, graph, vis) == false){
                return false;
                }
            }
        }
        //From this we have marked all the nodes to its respective sets

        /*No need to check
        // now we check if any consec nodes have same set

        for(int i = 0; i < m; i++){
            for(auto j : graph[i]){
                if(vis[i] == vis[j])return false;
            }
        }*/
        return true;

    }
};
class Solution {
public:
    bool bfs(int src, vector<vector<int>>& graph, vector<int>& vis){
        queue<int> q;//notes the node
        q.push(src);
        vis[src] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : graph[node]){
                if(vis[it] == -1){
                    q.push(it);
                    // if(vis[node] == 1){
                    //     vis[it] = 0;
                    // }
                    // else{
                    //     vis[it] = 1;
                    // }
                    vis[it] = !vis[node];
                }
                else if(vis[it] == vis[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
       /*Bipartite graph: Every adjacent node has different color, means every node can be separated in two set be it colors, node types, etc.*/
       /*Results:
       1)Every even cycle graph and every linear graph is bipartite 
       2)Every odd cycle graph is not bipartite*/
       //So we need to check is the graph has an odd cycle if yes then return false else return true
        int m = graph.size();
        int n = graph[0].size();
        vector<int> vis(m, -1);

        for(int i = 0; i < m; i++){
            if(vis[i] == -1){
            if(bfs(i, graph, vis) == false){
                return false;
                }
            }
        }
        //From this we have marked all the nodes to its respective sets

        /*No need to check
        // now we check if any consec nodes have same set

        for(int i = 0; i < m; i++){
            for(auto j : graph[i]){
                if(vis[i] == vis[j])return false;
            }
        }*/
        return true;

    }
};