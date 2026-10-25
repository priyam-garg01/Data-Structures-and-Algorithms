/*Given an undirected connected graph with V vertices numbered from 0 to V-1, the task is to implement both 
Depth First Search (DFS) and Breadth First Search (BFS) traversals starting from the 0th vertex.

The graph is represented using an array/vector of edges, where each element is a pair [u, v] indicating an 
undirected edge between vertex u and vertex v.

Example 1
Input: V = 5, edges = [ [0, 1], [0, 2], [0, 3], [2, 4] ]
Output:[0, 2, 4, 3, 1], [0, 2, 3, 1, 4]

Explanation:

DFS: Start from vertex 0. Visit vertex 2, then vertex 4, backtrack to vertex 0, then visit vertex 3, 
and finally vertex 1. The traversal is 0 → 2 → 4 → 3 → 1.
BFS: Start from vertex 0. Visit vertices 2, 3, and 1 (in the order they appear in the adjacency list). 
Then, visit vertex 4 from vertex 2. The traversal is 0 → 2 → 3 → 1 → 4.

Example 2
Input: V = 4, edges = [ [0, 1], [0, 3], [1, 2] ]
Output: [0, 1, 2, 3], [0, 1, 3, 2]

Explanation:

DFS: Start from vertex 0. Visit vertex 1, then vertex 2, backtrack to vertex 0, then visit vertex 3. 
The traversal is 0 → 1 → 2 → 3.
BFS: Start from vertex 0. Visit vertices 1 and 3, then visit vertex 2 from vertex 1. 
The traversal is 0 → 1 → 3 → 2.*/
class Solution {
  public:
//   
//     void DfsTrav(int node, vector<vector<int>>& edges, vector<int>& ans, vector<int>& vis){
//         /*Right now, you are passing the graph edges by value:
//         This means C++ copies the entire graph every single time the function calls itself. For large graphs, this will cause your code to run out of memory (MLE) or take way too long (TLE).*/
//         if(edges[node].size() == 0){
//             ans.push_back(node);
//             vis[node] = 1;
//             return;
//         }
//         ans.push_back(node);
       
//         int size = edges[node].size();
//         for(int i = 0; i < size; i++){
//             if(vis[edges[node][i]] == 0){
//                 vis[edges[node][i]] = 1;
//                 DfsTrav(edges[node][i], edges, ans, vis);
//             }
//         }
//     }/*Scattered "Visited" Logic (Risk of Bugs)
// Right now, you are managing the vis array in three different places:

// Setting vis[0] = 1 in dfsOfGraph.
// Setting vis[node] = 1 inside the if(edges[node].size() == 0) block.
// Setting vis[edges[node][i]] = 1 inside the for loop before calling the recursion.
// Because the "visited" marking is scattered, it's very easy for a node to slip through or get handled inconsistently. For example, if you ever need to run DFS starting from a node other than 0, or if the graph has multiple disconnected components, this setup will quickly break down.*/
//     vector<int> dfsOfGraph(int V, vector<vector<int>> edges) {
//     vector<int> dfs;
//     vector<int> vis(V, 0);
//     vis[0] = 1;
//     int start = 0;
//     DfsTrav(start, edges, dfs, vis);
//     return dfs;
//     }
    void DfsTrav(int node, vector<vector<int>>& edges, vector<int>& ans, vector<int>& vis){
        
        vis[node] = 1;
        ans.push_back(node);

        for(auto it : edges[node]){
            if(!vis[it]){
            DfsTrav(it, edges, ans, vis);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<vector<int>> edges) {
        
        vector<int> dfs;
        vector<int> vis(V, 0);
        DfsTrav(0, edges, dfs, vis);
        return dfs;
    }
    
    vector<int> bfsOfGraph(int V, vector<vector<int>> edges) {
        queue<int> q;
        q.push(0);
        vector<int> visited(V, 0);
        visited[0] = 1;
        vector<int> bfsTrav;
        while(!q.empty()){
            int val = q.front();
            q.pop();
            int size = edges[val].size();
            for(int i = 0; i < size; i++){
                if(!visited[edges[val][i]]){
                    visited[edges[val][i]] = 1;
                    q.push(edges[val][i]);
                }
            } 
            bfsTrav.push_back(val);
        }
        return bfsTrav;
    }
};//T.C. = O(N) + O(2*E){We travel every nodes adj node, that is we travel times equal to degree of a node}{Degree of the graph as we saw before is equal to the twice of no of edges in the graph}
    // S.C. = O(3N)