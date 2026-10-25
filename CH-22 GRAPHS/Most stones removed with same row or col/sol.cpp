/*On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

 

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.
Example 3:

Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.
 

Constraints:

1 <= stones.length <= 1000
0 <= xi, yi <= 104
No two stones are at the same coordinate point.*/
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        
        //Firstly for declaring the size of ds we see the max row and max col
        int maxRow = -1;
        int maxCol = -1;
        for(int i = 0; i < n; i++){
            maxRow = max(maxRow, stones[i][0]);
            maxCol = max(maxCol, stones[i][1]);
        }

        DisjointSet ds(maxRow + maxCol + 2);//As indexing is zero based accessing maxRow + maxCol + 1 req size 1 more than that
        
            unordered_map<int, int> stoneNodes;//We store the column and rows of stone places in the map
        for(auto it : stones){
            int rowNode = it[0];
            int colNode = it[1] + maxRow + 1;
            //Here we store the col and row as separate nodes in the map and ds by makinng the counting of col start from num_of_rows + 1

            ds.unionBySize(rowNode, colNode);//Treats the stones occurring in the row or col as one connected comp which increments when stones of other rows and same col or same rows and other col are connected

            stoneNodes[rowNode] = 1;
            stoneNodes[colNode] = 1;
        }

        int cnt = 0;
        for(auto it : stoneNodes){
            if(ds.findUParent(it.first) == it.first){
                cnt++;
            }
        }
    return n - cnt;
    }
};/*We need to count the nodes that can be removed if there is an adj Node present to that --> This problem boils down to finding the number of components as from each component we remove (sizeComp - 1) stones --> Which leads to our answer which comes when each comp has only 1 stone left ==> (number of stones - number of components)
We store the row and col in cont integer notation in disjointSet by initiating col after maxRow
 /*By using the map, you ensure that you only count the ultimate parents of the rows and columns that actually contain at least one stone.*/