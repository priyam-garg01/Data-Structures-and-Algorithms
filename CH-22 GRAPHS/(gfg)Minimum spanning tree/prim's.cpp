/*Given a weighted, undirected, and connected graph with V vertices and a 2D array edges[][], where each element edges[i] = [u, v, w] represents an edge between vertices u and v with weight w, return the sum of the weights of all edges in the graph's Minimum Spanning Tree (MST).

Input: V = 3, E = 3, Edges = [[0, 1, 5], [1, 2, 3], [0, 2, 1]]
 
Output: 4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.
Input: V = 2, E = 1, Edges = [[0 1 5]]

 

Output: 5 
Explanation: Only one Spanning Tree is possible which has a weight of 5.
Constraints:
2 ≤ V ≤ 1000
V-1 ≤ E ≤ (V*(V-1))/2
1 ≤ w ≤ 1000
The graph is connected and doesn't contain self-loops & multiple edges.*/
class Solution{
    public:
    int spanningTree(int V, vector<vector<int>> edges) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        
        vector<vector<pair<int,int>>> adj(V);
        for(auto it : edges){//O(E)
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<int> vis(V, 0);
        int sumWt = 0;
        
        
        while(!pq.empty()){//O(ElogE) maximum number of edges associated with one node fills the space in q
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int EdgWt = it.first;
            
            if(vis[node])continue;
            sumWt += EdgWt;
            vis[node] = 1;
            
            for(auto it : adj[node]){//O(ElogE)
                int adjNode = it.first;
                int Wt = it.second;
                if(!vis[adjNode]){
                    pq.push({Wt, adjNode});//logE
                }
            }
        }
        return sumWt;
    }//T.C. = O(2*ElogE), S.C. = O(V*E) + O(E) 
};