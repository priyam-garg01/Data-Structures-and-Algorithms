/*Given a string, Find the longest palindromic subsequence length in given string.

A palindrome is a sequence that reads the same backwards as forward.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: s = "eeeme"

Output: 4

Explanation: The longest palindromic subsequence is "eeee", which has a length of 4.

Example 2:
Input: s = "annb"

Output: 2

Explanation: The longest palindromic subsequence is "nn", which has a length of 2.
Constraints:
1 ≤ s.length ≤ 1000*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
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
        int longestPalinSubseq(string s) {
            int n = s.size();
            //we can think of s == s1 and revS = s2 and then solve
            string s1;
            for(int i = n-1; i >= 0; i--){
                s1 += s[i];
            }
            return longestCommonSubseq(s, s1);
        }
};//Space optimiz can be done

