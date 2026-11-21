/*Given two strings str1 and str2, find the minimum number of insertions and deletions in string str1 required to transform str1 into str2.

Insertion and deletion of characters can take place at any position in the string.

Example 1:
Input: str1 = "kitten", str2 = "sitting"

Output: 5

Explanation: To transform "kitten" to "sitting", delete "k" to get "itten", insert "s" at the beginning to get "sitten", delete "e" to get "sittn", then insert "i" to get "sittin", and insert "g" at the end to get "sitting".To transform "kitten" to "sitting", delete "k" and insert "s" to get "sitten", then insert "i" to get "sittin", and insert "g" at the end to get "sitting".

Example 2:
Input: str1 = "flaw", str2 = "lawn"

Output: 2

Explanation: To transform "flaw" to "lawn", delete "f" and insert "n" at the end. Hence minimum number of operations required is 2".

Now Your Turn!
Pick the correct output for the given input
Input: str1 = "abcdef", str2 = "ghijkl"

Constraints:
1 ≤ str1.length, str2.length ≤ 1000*/
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
    int minOperations(string str1, string str2) { 
        int n1 = str1.size();
        int n2 = str2.size();
	    //To make string 1 to string 2 we need to make certain number of deletions and insertions
        //We find the LCS first and then subtract it from the len of 1st string --> that gives us the number of different chars to be deleted from str1 and/Or also insert new ones (2k operations) + if the len of str 2 is larger we need to insert new chars the remaining chars
        int common = longestCommonSubseq(str1, str2);
        int different = n1 - common;
        //If size equals 2*common gives ans
        //If n1 > n2 -> common(deletions) + n2 - LCS(insertions)
        //If n1 < n2 -> common(deletions) + n2 - LCS(insertions)

        if(n1 == n2)return 2*different;//n1 - common + n2 - common
        else return different + n2 - common; 
	} 
};