/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.*/
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*Num courses is the max number of courses we can take
        and the prereq defines that before completing the p.first we need to complete p.second where p is the pairs given as vectors in the prereq vector
        */
        int m = prerequisites.size();
        if(m == 0)return true;
        if(numCourses == 0)return false;


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

        if(ans.size() == n)return true;
        return false;
    }
};/*Using the topo sort 
We convert the prereq to a DAG using adj list
T.C. = O(M) + O(N) + O(N) + O(N + E)
S.C. = O(N + E) + O(N) + O(N)*/