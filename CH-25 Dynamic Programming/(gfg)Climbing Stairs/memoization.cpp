#include<bits/stdc++.h>
using namespace std;
/*There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time.

Count the number of ways, the person can reach the top (order does matter). 

Examples:

Input: n = 1
Output: 1
Explanation: There is only one way to climb 1 stair. 
Input: n = 3
Output: 3
Explanation: The following are three ways to reach the n-th stair.
 
Input: n = 4
Output: 5
Explanation: There are five ways to reach 4th stair: [1, 1, 1, 1], [1, 1, 2], [2, 1, 1], [1, 2, 1] and [2, 2].
Constraints:

1 ≤ n ≤ 40*/
class Solution {
  public:
    int numWays(int n){
        if(n == 0 || n == 1)return 1;
    
        return numWays(n-1) + numWays(n-2);
    }
  
    int countWays(int n) {
        
        return numWays(n);
    }//Recursive approach T.C. = O(2^n), S.C. = O(N)
};
class Solution {
  public:
    int numWays(int n, vector<int>& dp){
        if(n == 0 || n == 1)return dp[n] = 1;
        
        if(dp[n-1] != -1 && dp[n-2] != -1)return dp[n-1] + dp[n-2];
        
        if(dp[n-1] == -1)dp[n-1] = numWays(n-1, dp);
        if(dp[n-2] == -1)dp[n-2] = numWays(n-2, dp);
        
        return dp[n-1] + dp[n-2];
    }
  
    int countWays(int n) {
        vector<int> dp(n + 1, -1);
        
        return numWays(n, dp);
    }//T.C. = O(N), S.C. = O(2N)
};