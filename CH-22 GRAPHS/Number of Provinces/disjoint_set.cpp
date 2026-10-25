class DisjointSet{//finds which nodes have same component
    public:
    vector<int> parent, size;
    DisjointSet(int n){
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i < n; i++){
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
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //Disjoint set finds nodes belong to same components or not

        //We need to find the number of separate components

        int n = isConnected.size();

        DisjointSet ds(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(isConnected[i][j] == 1){
                //If i and j nodes has an edge between them
                ds.unionBySize(i, j);
            }
        }
    }
    //From the above loop we have stored the edges in the disjoint set data structure manner


    //For finding the number of connected components we count the number of bosses present that is how many nodes have parent[node] = node
    int count = 0;
        for(int i = 0; i < n; i++){
                if(ds.parent[i] == i){
                    count++;
                }
        }
        return count;
    }
};/*Using disjoint set:
T.C. = O(N^2), S.C. = O(N^2 + 2N)*/