#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestCommonSubseq(string str1, string str2){
        int n1 = str1.size();
        int n2 = str2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
            return dp[n1][n2];
    }
    int minInsertions(string s) {
        int n = s.size();
            //we can think of s == s1 and revS = s2 and then solve
            string s1;
            for(int i = n-1; i >= 0; i--){
                s1 += s[i];
            }
            return n - longestCommonSubseq(s, s1);
    }
};