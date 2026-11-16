#include<bits/stdc++.h>
using namespace std;
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
        vector<int> dp(n2, 0);
        vector<int> temp(n2, 0);

        int ct = 0;
            // if(text1[0] == text2[0])ct = 1;
            // dp[0] = ct;//i = 0, j = 0
            // if(n1 > 1 && text1[1] == text2[0])ct++;
            // temp[0] = ct;//i = 1, j = 0
        //for temp we need to correct it each time inside the loop
        ct = 0;
        for(int j = 0; j < n2; j++){//i = 0, j 
            if(text1[0] == text2[j])ct = 1;
            dp[j] = ct;
        }

        for(int i = 1; i < n1; i++){
            temp[0] = (text1[i] == text2[0]) ? 1 : dp[0];
            for(int j = 1; j < n2; j++){
                //C-I Matched
                if(text1[i] == text2[j]){
                    temp[j] = 1 + dp[j-1];
                    continue;
                }
                //C-II Unmatched
                int c1 = dp[j];
                int c2 = temp[j-1];

                temp[j] = max(c1, c2);
            }
            dp = temp;
        }


        return dp[n2-1];
        
    }
};/*ct incremented incorrectly instead of tracking whether a match was already found for row 0.
T.C. = O(M*N), S.C. = O(2*(min(M+N)))*/