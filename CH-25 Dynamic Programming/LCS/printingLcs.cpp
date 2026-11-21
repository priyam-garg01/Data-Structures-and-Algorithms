#include<bits/stdc++.h>
using namespace std;
    class Solution {
  public:
    

    int longestCommonSubstr (string str1, string str2){
        int n1 = str1.size();
        int n2 = str2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        // vector<int> dp(n2+1, 0);
        // vector<int> temp(n2+1, 0);
        
        for(int i1 = 1; i1 <= n1; i1++){
            for(int i2 = 1; i2 <= n2; i2++){
                //C-1 Match
                if(str1[i1-1] == str2[i2-1]){
                    dp[i1][i2] = 1 + dp[i1-1][i2-1];
                    continue;
                }
                //C-2 Unmatched
                dp[i1][i2] = max(dp[i1-1][i2], dp[i1][i2-1]);
            }
        }
        //T.C. = O(M+N), S.C. = O(M+N) +-> THE LCS PROBLEM
        string s ="";
        for(int i = 0; i < n1 + n2; i++)s += "$";
        int index = n1 + n2 -1;
        int i = n1;
        int j = n2;
        while(i && j){
                if(str1[i-1] == str2[j-1]){
                    //move to diagonal and store that char from backwards
                    s[index] = str1[i-1];
                    index--;
                    i--;
                    j--;
                }
                else{
                    //Move towards the cell which has given the max val
                    if(dp[i-1][j] > dp[i][j-1])i--;
                    else j--;
                }
        }
        // reverse(s.begin(), s.end());
    }
};