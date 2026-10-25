/*You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

Example 1:



Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
Example 2:



Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
Example 3:


Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.*/
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
//notes the edDiff and the index of the cell


    vector<vector<int>> edDiff(m, vector<int>(n, 1e9));
    //Stores the difference between two edges
    edDiff[0][0] = 0;

    pq.push({0, {0, 0}});

    vector<int> Row = {1, 0, -1, 0};
    vector<int> Col = {0, -1, 0, 1};
    // To calc effort at every iteration we need to remember the edW of the previous one


    while(!pq.empty()){
        int Wt = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();

if(row == m-1 && col == n-1)return Wt;
    for(int i = 0; i < 4; i++){
        int delRow = Row[i] + row;
        int delCol = Col[i] + col;

if(delRow >= 0 && delCol >= 0 && delRow < m && delCol < n){
        int newEff = max(Wt, abs(heights[row][col] - heights[delRow][delCol]));
        if(edDiff[delRow][delCol] > newEff){
        edDiff[delRow][delCol] = newEff;
        pq.push({newEff, {delRow, delCol}});//we add the edge diff of previous one to know the max edge diff that is effort at the end

                }
            }
        }
    }
   return 0;// just a placeholder that will never actually run. You could also write return -1; or return edDiff[m-1][n-1];—it won't change the result.


    }
};/*Dijkstra's algo updating the edDiff using the dist matrix and calc effort by comparing the max diff and curr nodes ed diff
T.C. = O(ELOGV); E = (M*N*4), V = (M*N), S.C. = O(M*N)
T.C. = O(M*N(LOG(M*N))*/