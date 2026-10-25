class Solution {
public:
    void dfsTrav(vector<vector<int>>& adjLs, int node, vector<int>& vis){
        vis[node] = 1;

            for(auto it : adjLs[node-1]){
                if(!vis[it]){
                    dfsTrav(adjLs, it, vis);
                }
            }
        }
    
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        //Here node indexing is 1 based means oth index of matrix represents the node 1


        //Creating adjacency list to reduce O(N^2)T.C.
        vector<vector<int>> adjLs(n);  
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjLs[i].push_back(j + 1);
                    adjLs[j].push_back(i + 1);  
                }
            }
        }

        int count = 0;
        vector<int> vis(n+1, 0);
        
        int node = 1;

        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                dfsTrav(adjLs, i, vis);
                count++;
            }
        }     

        return count;
    }
};/*Using the DFS traversal
T.C. = O(N) + O(V + 2*E), S.C. = O(N) + O(N){Skewed tree depth}
T.C. = O(2N) = O(N), S.C. = O(2N) = O(N)
Similarly bfs*/