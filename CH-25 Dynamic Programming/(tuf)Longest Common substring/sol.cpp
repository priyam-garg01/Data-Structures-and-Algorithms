/*Given two strings str1 and str2, find the length of their longest common substring.

A substring is a contiguous sequence of characters within a string.

Example 1:
Input: str1 = "abcde", str2 = "abfce"

Output: 2

Explanation: The longest common substring is "ab", which has a length of 2.

Example 2:
Input: str1 = "abcdxyz", str2 = "xyzabcd"

Output: 4

Explanation: The longest common substring is "abcd", which has a length of 4.

Now Your Turn!
Pick the correct output for the given input
Input: str1 = "abcdef", str2 = "ghijkl"


1

6

0

2

Constraints:
n=str1.length
m=str2.length
1<= n, m <=103
str1 and str2 are in lowercase alphabet*/

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public: 
    int longestCommonSubstr (string str1, string str2){
        int n1 = str1.size();
        int n2 = str2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        int maxLenSubstr = 0;
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    maxLenSubstr = max(maxLenSubstr, dp[i][j]);
                }
                else dp[i][j] = 0;
            }
        }

        // //Backtracking the dp table
        // //This doesnot solves our case when the maxLensubs != maxLenSubstr
        // int lenSubst = 0;
        // int maxLenSubst = 0;
        // int i = n1; int j = n2;
        // while(i > 0 && j > 0){
        //         if(str1[i-1] == str2[j-1]){
        //             lenSubst += 1;
        //             i--;
        //             j--;
        //         }
        //         else{
        //             maxLenSubst = max(lenSubst, maxLenSubst);
        //             lenSubst = 0;
        //             if(dp[i-1][j] > dp[i][j-1])i--;
        //             else j--;
        //         }
        // }//Doesnt increment if the first char that is last iteration of the loop is matching
        // maxLenSubst = max(lenSubst, maxLenSubst);

        return maxLenSubstr;
    } 
};

