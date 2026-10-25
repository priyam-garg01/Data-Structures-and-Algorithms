/*Given an n x m matrix grid where each cell contains either 0 or 1, determine the shortest distance between a source cell and a destination cell. You can move to an adjacent cell (up, down, left, or right) if that adjacent cell has a value of 1. The path can only be created out of cells containing 1. If the destination cell is not reachable from the source cell, return -1.


Example 1

Input: grid = [[1, 1, 1, 1],[1, 1, 0, 1],[1, 1, 1, 1],[1, 1, 0, 0],[1, 0, 0, 1]], source = [0, 1], destination = [2, 2]

Output: 3

Explanation: The shortest path from (0, 1) to (2, 2) is:

Move down to (1, 1)

Move down to (2, 1)

Move right to (2, 2)

Thus, the shortest distance is 3

Example 2

Input: grid = [[1, 1, 1, 1, 1],[1, 1, 1, 1, 1],[1, 1, 1, 1, 0],[1, 0, 1, 0, 1]], source = [0, 0], destination = [3, 4]

Output: -1

Explanation: 

Since, there is no path possible between the source cell and the destination cell, hence we return -1.*/
class Solution{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        int n = grid.size();
        int m = grid[0].size();

    // priority_queue<pair<int, pair<int, int>> , vector<pair<int, pair<int, int>>>, greater<pair <int, pair<int, int>>> > pq;
    //As the edW are of unit distance we can use simple q and the extra logV of 

    queue<pair<int, pair<int, int>>> q;
    /*If dist[node] is INT_MAX, adding even a tiny edge weight to it will cause an integer overflow, turning it into a negative number and messing up your code.

Using 1e9 is safe because even if you add a large edge weight to it, it won't overflow a standard 32-bit integer.*/
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        if(source.first == destination.first && source.second == destination.second) return 0; 
        // pq.push({0, source});
        q.push({0, source});
        dist[source.first][source.second] = 0;

        vector<int> row = {1, 0, -1, 0}; 
        vector<int> col = {0, -1, 0, 1}; 
        while(/*!pq.empty()*/!q.empty()){
            // int dis = pq.top().first;
            // int Row = pq.top().second.first;
            // int Col = pq.top().second.second;
            // pq.pop();
            int dis = q.front().first;
            int Row = q.front().second.first;
            int Col = q.front().second.second;
            q.pop();

            if(Row == destination.first && Col == destination.second && dist[Row][Col] != 1e9)return dist[Row][Col];
        //We store ans in the dist arr 
            for(int i = 0; i < 4; i++){
                int delRow = row[i] + Row;
                int delCol = col[i] + Col;

                if(delRow >= 0 && delCol >= 0 && delRow < n && delCol < m && grid[delRow][delCol] == 1 && dist[delRow][delCol] > dis + 1){
                    // pq.push({dis + 1, {delRow, delCol}});
                    q.push({dis + 1, {delRow, delCol}});
                    dist[delRow][delCol] = dis + 1;
                }
            }

        }
        return -1;
    }
};//T.C. = O(M*N), S.C. = O(2*M*N)