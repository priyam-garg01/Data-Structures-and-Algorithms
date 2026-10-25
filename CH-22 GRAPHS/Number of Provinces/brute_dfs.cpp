/*There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3*/
class Solution {
public:
    void dfsTrav(vector<vector<int>>& isConnected, int node, vector<int>& vis){
        vis[node] = 1;

        for(int i = 0; i < isConnected[node-1].size(); i++){
            // if(!vis[isConnected[node-1][i]]){//Since isConnected is an adjacency matrix, isConnected[node-1][i] is going to be either 0 or 1 
            if(isConnected[node-1][i] == 1 && !vis[i+1]){
                dfsTrav(isConnected, i + 1, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        //Here node indexing is 1 based means oth index of matrix represents the node 1
        int count = 0;
        vector<int> vis(n+1, 0);
        int node = 1;

        while(node <= n){
            if(!vis[node]){
                dfsTrav(isConnected, node, vis);
                count++;
            }
            node++;
        }        

        return count;
    }
};/*Using the DFS traversal
T.C. = O(N) + O(N*N){MATRIX TRAVERSAL}, S.C. = O(N) + O(N) {Skewed tree depth}*/