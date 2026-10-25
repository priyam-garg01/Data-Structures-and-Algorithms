/*Given an undirected graph with V vertices labeled from 0 to V-1. The graph is represented using an adjacency list where adj[i] lists all nodes connected to node. Determine if the graph contains any cycles.

Note: The graph does not contain any self-edges (edges where a vertex is connected to itself).


Example 1
Input: V = 6, adj= [[1, 3], [0, 2, 4], [1, 5], [0, 4], [1, 3, 5], [2, 4]]

Output: True

Explanation: The graph contains a cycle: 0 ->1 -> 2 -> 5 -> 4 -> 1.

Example 2
Input: V = 4, adj= [[1, 2], [0], [0, 3], [2]]

Output: False

Explanation: The graph does not contain any cycles. */
class Solution{
public:
    bool detectCycle(int src, vector<int> adj[], vector<int>& vis){
        /*vector<int>& adj[]
In C++, the compiler gets a bit confused when you try to pass an array of references like that. It's actually not allowed by the language rules.*/
        queue<pair<int, int>> q;//Stores the node value and its parent
        vis[src] = 1;
        q.push({src, -1});

        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto adjNode : adj[node]){
                if(!vis[adjNode]){
                    vis[adjNode] = 1;
                    q.push({adjNode, node});
                }
                else if(parent != adjNode){//If the parent of the curr node{0} is not equal to adj node{4} still it is visited via {1}
                //if someone is visted and hasn't come from it like 3->4 so we say that it has traversed a different path
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        // int src = adj[0][0];
        //adj[0][0] may not exist
        //We run a loop for the V vertices and if get ajd[v][i] we call detectCycle

        // int src = -1;
        // for(int i = 0; i < V; i++){
        //     for(auto it : adj[i]){
        //         if(!vis[it]){
        //         src = it;
        //         break;
        //         }
        //     }
        // } 
        
        //If we had connected components
        for(int i = 0; i < V; i++){
            // for(auto it : adj[i]){
            //     if(!vis[it]){
            //        if(detectCycle(it, adj, vis))return true; 
            //     }
            // }
            //Extra work
            //We can directly check visited of i
            if(!vis[i]){
                if(detectCycle(i, adj, vis))return true;
            }
        }

        return false;
    }//T.C. = O(N + D) + O(N){For loop} = O(N + 2E), S.C. = O(2N)
};