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
                else{
                    ds.unionBySize(it[0], it[1]);
                }
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
};/*Slight optimisation of if else in first loop*/