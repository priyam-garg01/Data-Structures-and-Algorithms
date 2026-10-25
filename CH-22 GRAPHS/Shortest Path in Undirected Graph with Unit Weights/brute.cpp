/*Given a Undirected Graph of N vertices from 0 to N-1 and M edges and a 2D Integer array edges, where there 
is a edge from vertex edges[i][0] to vertex edges[i][1] of unit weight.

Find the shortest path from the source to all other nodes in this graph. In this problem statement, 
we have assumed the source vertex to be ‘0’. If a vertex is unreachable from the source node, then return -1 
for that vertex.

Example 1
Input: n = 9, m = 10, edges = [[0,1],[0,3],[3,4],[4,5],[5, 6],[1,2],[2,6],[6,7],[7,8],[6,8]]

Output: 0 1 2 1 2 3 3 4 4



Explanation:

The above output array shows the shortest path to all 

the nodes from the source vertex (0), Dist[0] = 0, Dist[1] = 1 , Dist[2] = 2 , …. Dist[8] = 4.Where 
Dist[node] is the shortest path between src and the node. For a node, if the value of Dist[node]= -1, then we 
conclude that the node is unreachable from the src node.

Example 2

Input: n = 8, m = 10, edges =[[1,0],[2,1],[0,3],[3,7],[3,4],[7,4],[7,6],[4,5],[4,6],[6,5]]



Output: 0 1 2 1 2 3 3 2

Explanation: 
The above output list shows the shortest path to all the nodes from the source vertex (0), 
Dist[0] = 0, Dist[1] = 1, Dist[2] = 2,.....Dist[7] = 2.*/
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M){
        //since it is an undirected graph we cannot use the topo sort approach
        // make adj List
        vector<vector<int>> adj(N);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        queue<pair<int, int>> q;
        vector<int> vis(N, 0);
        int src = 0;
        q.push({src, 0});
        vector<int> dist(N, INT_MAX);
        vis[src] = 1;
        while(!q.empty()){
            int node = q.front().first;
            int d = q.front().second;
            
            q.pop();
            if(d < dist[node]){
                dist[node] = d;
            }

            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it, d + 1});
                }
            }
        }
        for(int i = 0; i < N; i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }

        return dist;
    }//T.C. = O(M) + O(N) + O(N), S.C. = O(M + N) + O(3N);
};/*Why this works? we know that our src that is zero is already in the sorted order that it comes first and the
distance keep on increasing by as we reach the adj nodes as they are already sorted from the src */ 
/*Since all edges here have a unit weight of 1, a standard BFS queue naturally processes nodes level-by-level
 (distance 0, then 1, then 2, etc.), which gives us that same guarantee without needing a topo sort.*/