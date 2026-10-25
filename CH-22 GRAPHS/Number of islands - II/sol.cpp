/*Given a grid of n rows and m columns. Initially, all cells of the grid contain 0, where 0 represents water.

You are also given a 2D array operators[][] of size k, where each operator contains two integers representing the row and column of a cell.
Each operation converts the specified water cell into land by changing its value from 0 to 1.
Return an array containing the number of islands after each operation.

An island is a group of one or more land cells (or 1s) with the following properties,

1s are connected through their top, bottom, left, or right sides.
Diagonally connected are not considered part of the same island.
Examples:

Input: n = 4, m = 4, k = 4, operators[][] = [[1,1],[0,1],[3,3],[3,4]]
Output: [1, 1, 2, 2]
Explanation: Grid after each operation are shown below.

Input: n = 4, m = 5, k = 4, operators[][] = [[0,0],[1,1],[2,2],[3,3]]
Output: [1, 2, 3, 4]
Explanation: Grid after each operation are shown below.

Constraints:

1 ≤ n, m ≤ 100
1 ≤ k ≤ 105
operators.size() = k
2 ≤ operators[i].size() ≤ 2
operator[i][0] < n
operator[i][1] < n*/
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
class Solution{
public:
vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators){
        //We create a Disjoint Set which will have M*N elements

    DisjointSet ds(m*n);
        //We create like for like elements for pairs (1, 1) == 1*m + n

    int ct = 0;
    vector<int> ans;
    vector<int> vis(m*n, 0);//To note that we have prev vis a certain node
    int delRow[] = {-1, 0, 0, 1};
    int delCol[] = {0, 1, -1, 0};
    for(auto it : operators){
        int node = it[0]*m + it[1];

        if(vis[node]){
            //If already vis we first insert the same ct and then countinue
            ans.push_back(ct);
            continue;
        }

        if(!vis[node]){
            vis[node] = 1;
            ct++;

            for(int i = 0; i < 4; i++){
                int row = it[0] + delRow[i];
                int col = it[1] + delCol[i];

                if(row < n && col < m && row >= 0 && col >=0){
                    int adjNode = row*m + col;
                    if(vis[adjNode]){
                        if(ds.findUParent(adjNode) != ds.findUParent(node)){
                            ct--;
                            ds.unionBySize(node, adjNode);
                        }
                    }
                }

            }
        }
        ans.push_back(ct);
    }
    return ans;   
    }
};