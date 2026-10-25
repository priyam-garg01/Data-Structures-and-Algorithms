/*Given a Directed Acyclic Graph of N vertices from 0 to N-1 and M edges and a 2D Integer array edges, where there is a directed edge from vertex edge[i][0] to vertex edge[i][1] with a distance of edge[i][2] for all i.



Find the shortest path from source vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex. The source vertex is assumed to be 0.


Example 1



Input: N = 4, M = 2 edge = [[0,1,2],[0,2,1]]



Output: 0 2 1 -1



Explanation:

Shortest path from 0 to 1 is 0->1 with edge weight 2. 

Shortest path from 0 to 2 is 0->2 with edge weight 1.

There is no way we can reach 3, so it's -1 for 3.

Example 2

Input: N = 6, M = 7 edge = [[0,1,2],[0,4,1],[4,5,4],[4,2,2],[1,2,3],[2,3,6],[5,3,1]]



Output: 0 2 3 6 1 5



Explanation:

Shortest path from 0 to 1 is 0->1 with edge weight 2. 

Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3.

Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6.

Shortest path from 0 to 4 is 0->4 with edge weight 1.

Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.*/

class Solution {
    public:

    void dfs(int src, vector<pair<int, int>> adj[], vector<int>& vis, stack<int>& st){//O(N + M)
        vis[src] = 1;
        for(auto it : adj[src]){
            if(!vis[it.first]){
                dfs(it.first, adj, vis, st);
            }
        }
        st.push(src);
    }
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
            //we are given a triplet where first is the vertex second its edge and third the distance
            //we do not need to find the distance between every node we just need to find the shortest distance of every node from the source node

        vector<int> distance(N, -1);
        vector<pair<int, int>> adj[N];//vector<vector<pair<int, int>>> adj(N)

        //We store the adjList in form of pairs including the distance from the connected node

    // Skip nested loops
        // for(int i = 0; i < N; i++){
        //     for(auto it : edges[i]){
        //         adj[it[0]].push_back(({it[1], it[2]}));
        //     }
        // }
        for(int i = 0; i < M; i++){//vertices are n but edges are m
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});//O(M)
        }
        vector<int> vis(N, 0);
        stack<int> st;
        for(int i = 0; i < N; i++){//O(N)
            if(!vis[i]){
                dfs(i, adj, vis, st);
            }
        }
        //from here we get our stack which is in the topo order
        vector<int> dist(N, INT_MAX);
        int src = 0;
        dist[src] = 0;
        while(!st.empty()){//O(N)
            int node = st.top();
            st.pop();
             // Only process if the node is reachable
            if(dist[node] != INT_MAX){
            for(auto it : adj[node]){//relax the edges
                dist[it.first] = min(dist[node] + it.second, dist[it.first]);
            }
        }
        }
        for(int i = 0; i < N; i++){
            if(dist[i] == INT_MAX)dist[i] = -1;
        }
        return dist;
    }
};/*T.C. = O(M) + O(N) + O(M + N) + O(N), S.C. = O(M + N) + O(N) + O(2N) + O(N)
    T.C. = O(2M + 3N), S.C. = O(M + 5N)*/

/*S-1Make the adj list where the connected node and the wt will be stored in a vector of pairs
  S-2 Apply topo sort using any method bfs or dfs and then empty that ans vector or stack 
  S-3 while filling the dist vector with relax the edges method by initially putting the INT_MAX in dist vec

  Think of the estimate of the shortest path as a tight, stretched rubber band. 
  Every time you find a shorter path, you let go of some of that tension because the path gets shorter 
  and more accurate. You are "relaxing" the constraint on that distance.*/

  /*Why we USED TOPO :
  We know it gives us the nodes in order of increasing inDeg so it is predicted that we are not leaving anyone behind 
  and moving in correct direction*/