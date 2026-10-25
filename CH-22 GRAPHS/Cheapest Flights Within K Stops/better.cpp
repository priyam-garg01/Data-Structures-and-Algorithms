class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int, int>>> adj(n);//Directed adjList

        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

queue<pair<pair<int,int>, int>> q;//Since the number of stops is our constraint and not the dist we desiagn pair as stops, dist

    q.push({{0, 0}, src});

    vector<int> dist(n, 1e9);
    dist[src] = 0;
    while(!q.empty()){
        int stops = q.front().first.first;
        int dis = q.front().first.second;
        int node = q.front().second;
        q.pop();

        // if(node != dst || node != src)stops = stops + 1;
        //the statement always runs so we increment stops in the loop only

    // if(node == dst && stops <= k)return dis;
    //We may get better price with same stops on the next iteration
        if(stops > k)continue;
        for(auto it : adj[node]){
            if(dist[it.first] > dis + it.second && stops <= k){
            dist[it.first] = dis + it.second;
            q.push({{stops + 1, dist[it.first]}, it.first});
            }
        }
    }
    if(dist[dst] != 1e9)return dist[dst];
    return -1;
    }
};/*T.C. = O(E), S.C. = O(E + V) */