/*There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

 

Example 1:


Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
Example 2:


Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2
Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.
 

Constraints:

1 <= n <= 105
1 <= connections.length <= min(n * (n - 1) / 2, 105)
connections[i].length == 2
0 <= ai, bi < n
ai != bi
There are no repeated connections.
No two computers are connected by more than one cable.*/
class DisjointSet{
public:
    vector<int> size, parent;
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int findUParent(int u){
        if(parent[u] == u)return u;

        return parent[u] = findUParent(parent[u]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v)return;

        if(size[ulp_v] > size[ulp_u]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
            }
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        //Firstly we count the number of connected components by applying the disjoint set
        DisjointSet ds(n);
        int m = connections.size();
        int extra = 0;
            for(auto it : connections){
                if(ds.findUParent(it[0]) == ds.findUParent(it[1])){
                    extra++;
                }
                ds.unionBySize(it[0], it[1]);
            }

        int nc = 0;
        for(int i = 0; i < n; i++){
                if(ds.parent[i] == i){
                    nc++;
            }
        }
        if(extra >= nc - 1){
            return nc - 1;
        }
        return -1;
    }
};/*We take the disjoint set to solve the given connections matrix:
Firstly while inserting in disjoint sets we check if the inserted edge is extra or not that means if the edge is not there still the new edge can be indirectly connected
and take number of extras in note
Then we find the number of connected components
T.C. = O(E) + O(N), S.C. = O(2N) + O(2*E)
*/