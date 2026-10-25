class Solution {
public:
    void bfsTrav(vector<vector<int>>& isConnected, int node, vector<int>& vis){
        queue<int> q;
        q.push(node);
        vis[node] = 1;

        while(!q.empty()){
            int val = q.front();//since val is starting from 1 we need isConnected[val-1]and not just val
            q.pop();
for(int i = 1; i <= isConnected[val-1].size(); i++){
        // int it = isConnected[val][i];We are just iterating over row values wjich are just 0 and 1
        if(isConnected[val-1][i-1] == 1 && !vis[i]){
                    q.push(i);
                    vis[i] = 1;
                }
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
                bfsTrav(isConnected, node, vis);
                count++;
            }
            node++;
        }

        return count;
    }
};/*Using the BFS traversal:
T.C. = O(N) + O(N*N)
S.C. = O(N) + O(N){ For queue worst-case scenario (like if all nodes are directly connected to one central node)}*/