class Solution
{
public:
    int celebrity(vector<vector<int>> &M){
        int n = M.size();

    int top = 0;
    int bottom = n-1;

    while(top < bottom){
        if(M[top][bottom] == 0 && M[bottom][top] == 1){
            bottom--;
        }
        else if(M[top][bottom] == 1 && M[bottom][top] == 0){
            top++;
        }
        else{//if both aren't celebrity
            top++;//neither top nor bottom is celeb
            bottom--;
        }
    }
    if(top > bottom)return -1;

    for(int i = 0; i < n; i++){
        if(i == top)continue;//DIAGONAL
        if(M[top][i] == 0 && M[i][top] == 1){
            continue;
        }
        else return -1;
    }
    return top;



    /*
    //At last top = bottom check for zeroes
    for(int i = 0; i < n; i++){
        if(M[top][i] == 1){
            return -1;
        }
    }
    return top;
    */
    }
};//There can be only 1 celeb or no celeb
/*Using the two pointer approach 
// T.C. = O(N) + O(N), S.C. = O(1)
*/