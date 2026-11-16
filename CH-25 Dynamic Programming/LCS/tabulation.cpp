#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, 0));
        int ct = 0;
        for(int i = 0; i < n1; i++){
            if(text1[i] == text2[0])ct = 1;
            dp[i][0] = ct;
        }
        ct = 0;
        for(int j = 0; j < n2; j++){
            if(text1[0] == text2[j])ct = 1;
            dp[0][j] = ct;
        }

        for(int i = 1; i < n1; i++){
            for(int j = 1; j < n2; j++){
                //C-I Matched
                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    continue;
                }
                //C-II Unmatched
                int c1 = dp[i-1][j];
                int c2 = dp[i][j-1];

                dp[i][j] = max(c1, c2);
            }
        }


        return dp[n1-1][n2-1];
        
    }
};