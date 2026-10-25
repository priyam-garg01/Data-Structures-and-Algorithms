class Solution {
public:
    
   
    int orangesRotting(vector<vector<int>>& grid) {

        /*0 --> empty cell
        1 --> fresh orange
        2 --> rotten orange
        */
//If we find a val 2 we do the bfs to mark all of its adjacent mangoes as rotten (2)
//At last if we find any mango as 1 we return -1
    int m = grid.size();
    int n = grid[0].size();
    int vis[m][n];
    queue<pair<pair<int, int>, int>> q;
    //Queue notes the row col pair and the time that is the number of traversal done by a rotten orage to '1' noted orange
    int cntFresh = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 2){
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else{
                vis[i][j] = 0;//as we have not marked in begining
            }
            if(grid[i][j] == 1)cntFresh++;
        }
    }
    //BFS TRAVERSAL
    int tm = 0;
    int delRow[] = {1, 0, -1, 0};
    int delCol[] = {0, 1, 0, -1};
    int cnt = 0;
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int t = q.front().second;
        tm = max(t, tm);
        q.pop();
        for(int i = 0; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
    if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2){
        q.push({{nrow, ncol}, t + 1});
        vis[nrow][ncol] = 2;
        cnt++;//Notes every fresh orange that is being converted into rotten orange
            }
        }
    }
    // for(int i = 0; i < m; i++){
    //     for(int j = 0; j < n; j++){
    //         if(vis[i][j] != 2 &&grid[i][j] == 1)return -1;
    //         }
    //     }
    if(cnt != cntFresh)return -1;
        return tm;
    }
};/*Better:
Using cntfresh and cnt rottened replacing the additional O(M*N) checking complexity*/