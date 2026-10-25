class Solution {
public:
    void dfs(int row, int col, int& Color, int& color, vector<vector<int>>& image, vector<vector<int>>& image1, int delRow[], int delCol[]){
       
        image1[row][col] = color;

        // if(row > 0 && !vis[row - 1][col] && image1[row - 1][col] == Color){
        //     dfs(row - 1, col, color, Color, image1, vis);
        // }
        // if(col > 0 && !vis[row][col - 1] && image1[row][col - 1] == Color){
        //     dfs(row, col - 1, color, Color, image1, vis);
        // }
        // if(row < image1.size() - 1 && !vis[row + 1][col] && image1[row + 1][col] == Color){
        //     dfs(row + 1, col, color, Color, image1, vis);
        // }
        // if(col < image1[0].size() - 1 && !vis[row][col + 1] && image1[row][col + 1] == Color){
        //     dfs(row, col + 1, color, Color, image1, vis);
        // }
        int m = image1.size();
        int n = image1[0].size();
        for(int i = 0 ; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && image1[nrow][ncol] != color && image[nrow][ncol] == Color){//image1[nrow][ncol] != Color to check if it has already been visted
                dfs(nrow, ncol, Color, color, image, image1, delRow, delCol);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> image1 = image;
        // We donot need the visited matrix as we doing the traversal in a connected graph and not moving to other connnected componenets and can check using its copy only
        // vector<vector<int>> vis(m, vector<int>(n, 0));
        
        int iniColor = image[sr][sc];//mistake sr <=> sc

        if(iniColor == color)return image;//If the starting pixel already has the same color as the new color, your code will get stuck in an infinite loop

        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, -1, 0, +1};
        dfs(sr, sc, iniColor, color, image, image1, delRow, delCol);

        return image1;
    }
};/*Using the directional movement traversal:
T.C. = O(X) + O(4*X){As we move to 4 different nodes for every node(in the worst case)}X = TOTAL SIZE
S.C. = O(M*N) + O(M*N){Recursion stack space}
T.C. = O(M*N), S.C.  =O(M*N)*/

class Solution {
public:
    void bfs(int row, int col, int& Color, int& color, vector<vector<int>>& image, vector<vector<int>>& image1, int delRow[], int delCol[]){
        queue<pair<int, int>> q;
        q.push({row, col});
        int m = image1.size();
        int n = image1[0].size();

        while(!q.empty()){
            row = q.front().first;
            col = q.front().second;
            
            q.pop();
            image1[row][col] = color;
            
        for(int i = 0 ; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && image1[nrow][ncol] != color && image[nrow][ncol] == Color){//image1[nrow][ncol] != Color to check if it has already been visted
                q.push({nrow, ncol});
            }
        }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> image1 = image;
        // We donot need the visited matrix as we doing the traversal in a connected graph and not moving to other connnected componenets and can check using its copy only
        // vector<vector<int>> vis(m, vector<int>(n, 0));

        int iniColor = image[sr][sc];//mistake sr <=> sc

        if(iniColor == color)return image;//If the starting pixel already has the same color as the new color, your code will get stuck in an infinite loop

        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, -1, 0, +1};
        bfs(sr, sc, iniColor, color, image, image1, delRow, delCol);

        return image1;
    }
};/*Using the bfs traversal*/