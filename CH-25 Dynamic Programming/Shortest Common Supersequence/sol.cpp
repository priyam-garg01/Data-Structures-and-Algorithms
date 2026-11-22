/*Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of lowercase English letters.*/
#include<bits/stdc++.h>
using namespace std;
//Just do the backtracking of the LCS Dp table
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        // //This was how we found the LCS 
        // string Lcs;
        // for(int i = 0; i < dp[m][n]; i++)Lcs.push_back('#');
        // int i = m; int j = n;
        // int ind = dp[m][n]-1;
        // while(i && j){
        //     if(str1[i-1] == str2[j-1]){
        //         Lcs[ind] = str1[i-1];
        //         i--;
        //         j--;
        //         ind--;
        //     }
        //     else{
        //         if(dp[i-1][j] > dp[i][j-1])i--;
        //         else j--;
        //     }
        // }

        // For SCS we find len ==> len(A) + Len(B) - dp[m][n]
        int len = m + n - dp[m][n];
        string ans;
        for(int i = 0; i < len; i++)ans.push_back('#');
        int i = m; int j = n;
        int ind = len-1;
        while(i && j){
            if(str1[i-1] == str2[j-1]){
                ans[ind] = str1[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    ans[ind] = str1[i-1];
                    i--;
                }
                else {
                    ans[ind] = str2[j-1];
                    j--;
                }
            }
            ind--;
        }
        //If somthing of any string remains
        if(ind >= 0){
            if(i != 0){
                while(i){
                    ans[ind] = str1[i-1];
                    i--;
                    ind--;
                }
            }
            else{
                while(j){
                    ans[ind] = str2[j-1];
                    ind--;
                    j--;
                }
            }
        }


        return ans;

    }
};/*T.C. = O(M*N + M + N), S.C. = O(M*N + M + N)*/
