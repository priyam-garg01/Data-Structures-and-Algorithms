class Solution {
  public:
    bool dfs(int node, vector<vector<int>>& adjList, vector<int>& vis){
        vis[node] = 2;
        for(auto it : adjList[node]){
            if(!vis[it]){
                if(dfs(it, adjList, vis) == true)return true;
            }
            else if(vis[it] == 2){
                return true;
            }
        }
        //While backtracking we remove the mark that node has been travelled
        vis[node] = 1;//marked only as visited
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        //First we create an adjacency list
        vector<vector<int>> adjList(V);
        for(int i = 0; i < edges.size(); i++){//size will be of edges as one or more vertex may or may not have a direction
            adjList[edges[i][0]].push_back(edges[i][1]);
        }
        
        vector<int> vis(V, 0);
        //Using single vis with vis as 1 and path as 2
        
        for(int i = 0;i < V; i++){
            if(!vis[i]){
                if(dfs(i, adjList, vis) == true)return true;
            }
        }
        
        return false;
    }
};//S.C. = O(V){VIS} + O(V + E)