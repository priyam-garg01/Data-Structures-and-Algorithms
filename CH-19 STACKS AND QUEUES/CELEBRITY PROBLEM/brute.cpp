/*A celebrity is a person who is known by everyone else at the party but does not know anyone in return. Given a square matrix M of size N x N where M[i][j] is 1 if person i knows person j, and 0 otherwise, determine if there is a celebrity at the party. Return the index of the celebrity or -1 if no such person exists.



Note that M[i][i] is always 0.


Example 1

Input: M = [ [0, 1, 1, 0], [0, 0, 0, 0], [1, 1, 0, 0], [0, 1, 1, 0] ]

Output: 1

Explanation: Person 1 does not know anyone and is known by persons 0, 2, and 3. Therefore, person 1 is the celebrity.

Example 2

Input: M = [ [0, 1], [1, 0] ]

Output: -1

Explanation: Both persons know each other, so there is no celebrity.*/

/*
class Solution
{
public:
    int celebrity(vector<vector<int>> &M){
        int n = M.size();
        //to find the row cum person that has all zeroes if not found return -1
// A celebrity satisfies both conditions:

// The celebrity knows nobody.
// Their row should contain all 0s. ////

// Everybody else knows the celebrity. XXXXXX{not satisfied}
// Their column should contain all 1s (except M[i][i], which is 0).
        for(int i = 0; i < n; i++){
            bool celeb = true;
            for(int j = 0; j < n; j++){
                if(M[i][j] == 1){
                    celeb = false;
                    break;
                }
            }
            if(celeb == true)return i;
        }
        return -1;
    }
};

*/
class Solution
{
public:
    int celebrity(vector<vector<int>> &M){
        int n = M.size();
    vector<int> iKnow(n,0);
    vector<int> knowMe(n,0);
   for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
        if(M[i][j] == 1){
        iKnow[i]++;
        knowMe[j]++;
    }
        }
      }
      for(int i = 0; i < n; i++){
        if(iKnow[i] == 0 && knowMe[i] == n-1){
            return i;
        }
      }
      return -1;
    }
};//There can be only 1 celeb or no celeb
/*Using extra arrays knowMe and iKnow
//T.C. = O(N^2)+O(N), S.C. = O(2N)
*/