/*Return the order else return an empty arr*/
class Solution {
public:
    void bfs(vector<vector<int>>& adjList, vector<int>& inDeg, vector<int>& ans, queue<int>& q){
    
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto it : adjList[node]){
                if(inDeg[it])inDeg[it]--;
                if(inDeg[it] == 0)q.push(it);
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        /*Num courses is the max number of courses we can take
        and the prereq defines that before completing the p.first we need to complete p.second where p is the pairs given as vectors in the prereq vector
        */
        int m = prerequisites.size();

    vector<vector<int>> adjList(numCourses);//Since the adj List size should be max of number of courses allowed to later match it up with logic of topological sort
   
   
    /*    for(int i = 0; i < m; i++){
     adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
            }
            */
        for(auto it : prerequisites){
            adjList[it[1]].push_back(it[0]);
        }

        int n = adjList.size();
        vector<int> inDeg(n, 0);

        for(int i = 0; i < n; i++){
            for(auto it : adjList[i]){
                inDeg[it]++;
            }
        }
        queue<int> q;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(inDeg[i] == 0){
                q.push(i);
            }
        }
        bfs(adjList, inDeg, ans, q);

        if(ans.size() == n)return ans;
        return {};
    }
};