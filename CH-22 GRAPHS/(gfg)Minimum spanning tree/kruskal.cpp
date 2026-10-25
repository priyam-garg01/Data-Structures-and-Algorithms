/*You are given a weighted, undirected, and connected graph with V vertices numbered from 0 to V-1.

The graph is provided in the form of an adjacency list, where each entry adj[u] contains a list of pairs [v, w], representing an edge between vertex u and vertex v with weight w.

Find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. 

A minimum spanning tree (MST) or minimum weight spanning tree is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices together, without any cycles and with the minimum possible total edge weight.

Note : The input to the function in code editor is giving in form of adjacency list.

Example 1:
Input: V = 4, adj = [[[1, 1], [3, 4]], [[0, 1], [2, 2]], [[1, 2], [3, 3]], [[0, 4], [2, 3]]

Output: 6

Explanation: 

Edges included in the MST:

From node 0 → [1, 1] (weight 1)
From node 1 → [2, 2] (weight 2)
From node 2 → [3, 3] (weight 3)
The total MST weight is 1 + 2 + 3 = 6.

These edges connect all vertices (0, 1, 2, 3) with minimum cost.

Example 2:


Input: V = 3, adj = [[[1, 5], [2, 15]], [[0, 5], [2, 10]], [[0, 15], [1, 10]]]

Output: 15

Explanation: 

Edges included in the MST:

From node 0 → [1, 5] (weight 5)
From node 1 → [2, 10] (weight 10)
The total weight of the MST is 5+10 = 15*/
class DisjointSet{
        vector<int> parent, size;

    public:
        DisjointSet(int n){
            parent.resize(n + 1);
            size.resize(n + 1, 1);
            for(int i = 0; i < n + 1; i++){
                parent[i] = i;
            }
        }

        int findUParent(int node){
            if(parent[node] == node)return node;

            return parent[node] = findUParent(parent[node]);
        }

        void unionBySize(int u, int v){
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);

            if(ulp_u == ulp_v)return;

            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    };
class Solution{
    public:
    
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        vector<pair<int,pair<int, int>>> edges;
        for(int i = 0; i < V; i++){
        for(auto it : adj[i]){
            int adjNode = it[0];
            int Wt = it[1];
            int node = i;
            edges.push_back({Wt, {node, adjNode}});
            }
        }

    sort(edges.begin(), edges.end());

        int mstWt = 0;
        // vector<pair<int, int>> mst;

        DisjointSet ds(V);
        //O(2E*4(ALPHA)*2)
        for(auto it : edges){
            int Wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if(ds.findUParent(u) != ds.findUParent(v)){
                mstWt += Wt;
                // mst.push_back({u, v});
                ds.unionBySize(u, v);
            }
        }

        
    return mstWt;
    }
};//T.C. = O(V + 2E) + O((2E)LOG(2E)) + O(2E*(1)) = O(E(LOG(E))), S.C. = O(V + 2E) + O(2V)