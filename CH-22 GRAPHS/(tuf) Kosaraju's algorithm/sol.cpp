/*You are given a directed graph with V vertices, numbered from 0 to V − 1, and its adjacency list Adj, where Adj[i] contains all vertices j such that there is a directed edge from vertex i to vertex j.

Your task is to find the number of strongly connected components (SCCs) in the graph.

Example 1:
Input: V=5, Adj=[[2,3],[0],[1],[4],[]]



Output: 3

Explanation: Three strongly connected components are marked below:



Example 2:
Input: V=8, Adj=[[1],[2],[0,3],[4],[5,7],[6],[4,7],[]]

Output: 4

Explanation: Four strongly connected components are marked below:

*/
class Solution{
public:

    void dfs(int node, vector<int>& vis, vector<int> adj[], stack<int>& st){
        vis[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }
    void dfs1(int node, vector<int>& vis, vector<int> adj[], vector<int>& ans){
        vis[node] = 1;
        ans.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj, ans);
            }
        }
        
    }
    int kosaraju(int V, vector<int> adj[]){
    
      //Firstly we sort the finishing time of each dfs call for every node in a stack to get the order in which we find the ssc's  

    vector<int> vis(V, 0);
    stack<int> st;
    for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, vis, adj, st);
            }
      } 

    //Secondly we reverse the edges
    vector<int> adjT[V];//stores the reverse edges

    for(int i = 0; i < V; i++){
        vis[i] = 0;//To reuse in the final step
        for(auto it : adj[i]){
            adjT[it].push_back(i);
        }
    }

    vector<vector<int>> ans;
    int sccs = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();

        if(vis[node])continue;

        else{
            vector<int> scc;
            dfs1(node, vis, adjT, scc);
            ans.push_back(scc);
            sccs++;
        }
    }
        return sccs;
    }
};
//T.C. = O(V+ E) == S.C.