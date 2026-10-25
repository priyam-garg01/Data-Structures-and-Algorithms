/*There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.*/
class Solution {
public:
    void bfs(int src, vector<vector<int>>& graph, vector<int>& vis, queue<int> q){
        q.push(src);
        vis[src] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : graph[node]){
                if(vis[it] == -1){
                    q.push(it);
                    if(vis[node] == 1){
                        vis[it] = 0;
                    }
                    else{
                        vis[it] = 1;
                    }
                }
            }
        }
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


        queue<int> q;//notes the node

        for(int i = 0; i < m; i++){
            if(vis[i] == -1){
                bfs(i, graph, vis, q);
            }
        }
        //From this we have marked all the nodes to its respective sets

        // now we check if any consec nodes have same set

        for(int i = 0; i < m; i++){
            for(auto j : graph[i]){
                if(vis[i] == vis[j])return false;
            }
        }
        return true;

    }
};/*Change vis to note the markings of two different groups and apply the vis bfs / dfs algo; later check the consecutive node groups. If they occur to be the same, return false; else, return true.
T.C. = O(N) + O(N + 2E) + O(N*N), S.C. = O(N) + O(N)
T.C. = O(N^2), S.C. = O(2N)*/
class Solution {
public:
    void dfs(int src, int group, vector<vector<int>>& graph, vector<int>& vis){
        vis[src] = group;

        for(auto it : graph[src]){
            if(vis[it] == -1){
                if(vis[src] == 1){
                    dfs(it, 0, graph, vis);
                    }
                else{
                    dfs(it, 1, graph, vis);
                    }
                }
            }
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


        queue<int> q;//notes the node

        for(int i = 0; i < m; i++){
            if(vis[i] == -1){
                dfs(i, 1, graph, vis);
            }
        }//Marking the disjoint sets too

        //From this we have marked all the nodes to its respective sets

        // now we check if any consec nodes have same set

        for(int i = 0; i < m; i++){
            for(auto j : graph[i]){
                if(vis[i] == vis[j])return false;
            }
        }
        return true;

    }
};