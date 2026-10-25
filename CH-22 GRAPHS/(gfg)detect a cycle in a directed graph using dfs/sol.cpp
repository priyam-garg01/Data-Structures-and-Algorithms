/*Given a directed graph with V vertices numbered from 0 to V - 1 and E directed edges. The graph is represented using a 2D array edges[][] of size E, where each entry edges[i] = [u, v] denotes a directed edge from vertex u to vertex v.

Check whether the graph contains any cycle. Return true if there exists at least one cycle in the graph; otherwise, return false.

Examples:

Input: V = 4, edges[][] = [[0, 1], [1, 2], [2, 0], [2, 3]]



Output: true
Explanation: The diagram clearly shows a cycle 0 -> 1 -> 2 -> 0
Input: V = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]


Output: false
Explanation: no cycle in the graph*/
class Solution {
  public:
    bool dfs(int node, vector<vector<int>>& adjList, vector<int>& vis, vector<int>& path){
        vis[node] = 1;
        path[node] = 1;
        for(auto it : adjList[node]){
            if(!vis[it]){
                if(dfs(it, adjList, vis, path) == true)return true;
            }
            else if(vis[it] == 1 && path[it] == 1){
                return true;
            }
        }
        //While backtracking we remove the mark that node has been travelled
        path[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        //First we create an adjacency list
        vector<vector<int>> adjList(V);
        for(int i = 0; i < edges.size(); i++){//size will be of edges as one or more vertex may or may not have a direction
            adjList[edges[i][0]].push_back(edges[i][1]);
        }
        
        vector<int> vis(V, 0);
//Along with vis we take a path tarversed vector so that if we travel different path it doesn't return us that the given graph has a cycle
        vector<int> path(V, 0);
        
        for(int i = 0;i < V; i++){
            if(!vis[i]){
                if(dfs(i, adjList, vis, path) == true)return true;
            }
        }
        
        return false;
    }
};//T.C. = O(V) + O(V) + O(V + E), S.C. = O(V){VIS} + O(V){PATH} O(V + E){ADJLIST}