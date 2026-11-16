#include<bits/stdc++.h>
using namespace std;
//To find the base cases we used 1 based indexing
class Solution {
public:

    int maxLenCommon(int i1, int i2, string text1, string text2, vector<vector<int>>& dp){
        if(i1 == 0 || i2 == 0)return 0;

        if(dp[i1][i2] != -1)return dp[i1][i2];
    
        //C-I Matched
        if(text1[i1-1] == text2[i2-1])return dp[i1][i2] = 1 + maxLenCommon(i1-1, i2-1, text1, text2, dp);

        //C-II Unmatched
        int c1 = maxLenCommon(i1-1, i2, text1, text2, dp);
        int c2 = maxLenCommon(i1, i2-1, text1, text2, dp);
        return dp[i1][i2] = max(c1, c2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        //Shift to 1 based indexing for tabulation
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
    
        return maxLenCommon(n1, n2, text1, text2, dp);
        
    }
};
class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        //Shift to 1 based indexing for tabulation
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for(int i = 0; i <= n1; i++)dp[i][0] = 0;
        for(int i = 0; i <= n2; i++)dp[0][i] = 0;

        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                //C-I Matched
                if(text1[i-1] == text2[j-1])dp[i][j] = 1 + dp[i-1][j-1];

                //C-II Unmatched
                else{
                    int c1 = dp[i-1][j];
                    int c2 = dp[i][j-1];
                    dp[i][j] = max(c1, c2);
                }
            }
        }

        return dp[n1][n2];
        
    }
};
class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        //Shift to 1 based indexing for tabulation
        vector<int> dp(n2+1, 0);
        vector<int> temp(n2+1, 0);
        for(int i = 0; i <= n2; i++)dp[i] = 0;//i = 0, j

        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                //C-I Matched
                if(text1[i-1] == text2[j-1])temp[j] = 1 + dp[j-1];

                //C-II Unmatched
                else{
                    int c1 = dp[j];
                    int c2 = temp[j-1];
                    temp[j] = max(c1, c2);
                }
            }
                dp = temp;
        }

        return dp[n2];
        
    }
};