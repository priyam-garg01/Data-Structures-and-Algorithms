class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
      /*Intersections->nodes(Bidirectional)                 
        To find : the number of paths that takes shortest amt of time to reach n - 1 from 0*/

        vector<vector<pair<long long, long long>>> adj(n);

        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // int ct = 0;
        //Instead of ct we declare a ways vector which will tell us the number of paths a particular node has been traversed by in least amt of time
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>> > pq;

        vector<long long> time(n, 1e18), ways(n, 0);
        long long src = 0;
        time[src] = 0;
        ways[src] = 1;
        
        pq.push({0, src});
        long long modulo = (long long)(1e9 + 7);
        while(!pq.empty()){
            long long t = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                long long adjNode = it.first;
                long long tm = it.second;
                //This is the first time we travel to that node in shortest time
                if(time[adjNode] > tm + t){
                    time[adjNode] = tm + t;
                    ways[adjNode] = ways[node];
                    pq.push({time[adjNode], adjNode});
                }
                //Traversed before
                else if(time[adjNode] == tm + t) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % modulo;//number of ways the previous node travelled is added 
                }
            }
        }
        
    return ways[n-1]% modulo;
    }
};/*T.C. = O(ELOG(N)), S.C. = O(4N + E) long long is necessary for larger city inputs*/