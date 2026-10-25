/*There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

 

Example 1:


Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
Example 2:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
Example 3:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
 

Constraints:

2 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 104
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int, int>>> adj(n);//Directed adjList

        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

priority_queue<pair<pair<int,int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int> ,int>>> pq;//Since the number of stops is our constraint and not the dist we desiagn pair as stops, dist

    pq.push({{0, 0}, src});

    vector<int> dist(n, 1e9);
    dist[src] = 0;
    while(!pq.empty()){
        int stops = pq.top().first.first;
        int dis = pq.top().first.second;
        int node = pq.top().second;
        pq.pop();

        // if(node != dst || node != src)stops = stops + 1;
        //the statement always runs so we increment stops in the loop only

    // if(node == dst && stops <= k)return dis;
    //We may get better price with same stops on the next iteration
        if(stops > k)continue;
        for(auto it : adj[node]){
            if(dist[it.first] > dis + it.second && stops <= k){
            dist[it.first] = dis + it.second;
            pq.push({{stops + 1, dist[it.first]}, it.first});
            }
        }
    }
    if(dist[dst] != 1e9)return dist[dst];
    return -1;
    }
};/*T.C. = O(ELOG(V)) + O(E + V), V = N , E = FLIGHTS.SIZE() 
S.C. = O(N + E) + O(N) + O(N + E)*/