#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int maxLenCommon(int i1, int i2, string text1, string text2, vector<vector<int>>& dp){
        if(i1 == 0){
            if(text1[i1] == text2[i2])return 1;
            else if(i2 > 0)return dp[i1][i2] = maxLenCommon(i1, i2-1, text1, text2, dp);
            return 0;
        }
        if(i2 == 0){
            if(text1[i1] == text2[i2])return 1;
            else if(i1 > 0)return dp[i1][i2] = maxLenCommon(i1-1, i2, text1, text2, dp);
            return 0;
        }
        if(dp[i1][i2] != -1)return dp[i1][i2];
    
        //C-I Matched
        if(text1[i1] == text2[i2])return dp[i1][i2] = 1 + maxLenCommon(i1-1, i2-1, text1, text2, dp);

        //C-II Unmatched
        int c1 = maxLenCommon(i1-1, i2, text1, text2, dp);
        int c2 = maxLenCommon(i1, i2-1, text1, text2, dp);
        return dp[i1][i2] = max(c1, c2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        int ct = 0;
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return maxLenCommon(n1-1, n2-1, text1, text2, dp);
        
    }
};
//Striver
class Solution {
public:

    int maxLenCommon(int i1, int i2, string text1, string text2, vector<vector<int>>& dp){
        if(i1 < 0 || i2 < 0)return 0;

        if(dp[i1][i2] != -1)return dp[i1][i2];
    
        //C-I Matched
        if(text1[i1] == text2[i2])return dp[i1][i2] = 1 + maxLenCommon(i1-1, i2-1, text1, text2, dp);

        //C-II Unmatched
        int c1 = maxLenCommon(i1-1, i2, text1, text2, dp);
        int c2 = maxLenCommon(i1, i2-1, text1, text2, dp);
        return dp[i1][i2] = max(c1, c2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
    
        return maxLenCommon(n1-1, n2-1, text1, text2, dp);
        
    }
};/*T.C. = O(M*N), S.C. = O(M*N) + O(M+N)*/