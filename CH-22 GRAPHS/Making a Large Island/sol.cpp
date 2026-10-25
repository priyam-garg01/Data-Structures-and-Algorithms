/*You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] is either 0 or 1.*/
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        //We need to do reverse one '0' to '1' such that we get the largest island and return its size
        DisjointSet ds(n*n);
        int delRow[] = {1, 0, -1, 0};
        int delCol[] = {0, -1, 0, 1};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0)continue;

                if(grid[i][j] == 1){
                   for(int k = 0; k < 4; k++){
                    int row = i + delRow[k]; 
                    int col = j + delCol[k]; 
                    if(row >= 0 && col >= 0 && row < n && col < n){
                        if(grid[row][col] == 1){
                            int node = i*n + j;
                            int adjNode = row*n + col;
                            ds.unionBySize(node, adjNode);
                        }
                    }
                   } 
                }
            }
        }
        //Makes the connected components

        int maxSize = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1)continue;
                if(grid[i][j] == 0){
                    //We see the size of adjNode components and add 1 and store in max Size

                    int sizeComp = 0;
                    unordered_set<int> st;//To note the UParent components so that we do not note the same comp size more than once

                    for(int k = 0; k < 4; k++){
                    int row = i + delRow[k]; 
                    int col = j + delCol[k];

                    if(row >= 0 && col >= 0 && row < n && col < n){
                            int adjNode = row*n + col;
                        if(grid[row][col] == 1 && st.find(ds.findUParent(adjNode)) == st.end()){
                            int parent = ds.findUParent(adjNode);
                            st.insert(parent);
                            sizeComp += ds.size[parent];
                        }
                    }
                   }
                   maxSize = max(maxSize, sizeComp + 1); 
                }
            }
        
        }
            //Edge case where we do not find any 0 all ones
            if(maxSize == 0){
                return n*n;
            }
        return maxSize;
    }
};