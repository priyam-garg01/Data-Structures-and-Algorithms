/*Given a weighted undirected graph with V vertices numbered from 1 to V and E edges, where edges[i] = [u, v, w] denotes an undirected edge between vertices u and v with weight w. We are also given two vertices src and dest, find the shortest path from src to dest.

If multiple shortest paths exist with the same total weight, return the one whose sequence of vertices is lexicographically smallest.
If no path exists between src and dest, return {-1}.
Note: The graph contains no negative-weight edges.

Examples :
Input: V = 5, edges[][] = [[1, 2, 2], [2, 5, 5], [2, 3, 4], [1, 4, 1], [4, 3, 3], [3, 5, 1]], src = 1, dest = 5
Output: [1, 4, 3, 5]
Explanation: The shortest path from vertex 1 to vertex 5 is 1 -> 4 -> 3 -> 5 with a total weight of 5.

Input: V = 6, edges[][] = [[1, 2, 1], [1, 3, 1], [2, 4, 1], [3, 4, 1], [4, 6, 1], [2, 5, 2], [5, 6, 1]], src = 1, dest = 6
Output: [1, 2, 4, 6]
Explanation: There are two shortest paths from 1 to 6 with total weight 3: 1 -> 2 -> 4 -> 6 and 1 -> 3 -> 4 -> 6. Since [1, 2, 4, 6] is lexicographically smaller, it is returned.

Input: V = 5, edges[][] = [[1,2,4], [2,3,2], [4,5,1]], src = 1, dest = 5
Output: [-1]
Explanation: Since there are no edges, so no answer is possible.

Constraint:

2 ≤ V ≤ 10^5
0 ≤ E ≤ 2 × 10^5
1 ≤ edges[i][2] ≤ 10^4
1 ≤ src, dest ≤ V*/
class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        
        vector<vector<pair<int, int>>> adj(V + 1);//node numbering starts from 1

        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        pq.push({0, src});

        vector<int> dist(V + 1, INT_MAX);
        vector<int> parent(V + 1);
        for(int i = 0; i <= V; i++){//O(V)
            parent[i] = i;
        }
        //initialized parent of node to itself
        
        //Becz we have to store the path having the shortest dist from the src to the destination
        //we store the last node from which the curr iterating node came from

        dist[src] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for(auto it : adj[node]){
                    int adjNode = it.first;
                    int edW = it.second;
                    if(dist[adjNode] > dist[node] + edW){
                        dist[adjNode] = dist[node] + edW;
                        pq.push({dist[adjNode], adjNode});
                        parent[adjNode] = node;
                    }
                }
            }
        
        //if we get the dest node dist to be int max then we return empty arr
        if(dist[dest] == INT_MAX)return {};
        
        
        
        //now via the stored parent vector we travel back from dest to src
        
        // we put it into a stack to get the correct order
        
        //Or we can initiate a while loop that breaks when the parent of node is not the node itself
        
        int node = dest;
        vector<int> path;
        while(parent[node] != node){//O(V)
            path.push_back(node);
            node = parent[node];
        }
        //we also have to push the src node as it will be the only one in a cyclic graph whose parent will be the src itself
        path.push_back(src);
        reverse(path.begin(), path.end());

        return path;

        }
    };
//T.C. = O(E*LOG(V) + O(2V)), S.C. = O(V + E) + O(4V)