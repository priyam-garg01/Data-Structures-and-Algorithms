#include<bits/stdc++.h>
using namespace std;
class Solution{
    public: int longestCommonSubstr (string str1, string str2){
        int n1 = str1.size();
        int n2 = str2.size();

        vector<int> dp(n2+1, 0);
        vector<int> temp(n2+1, 0);
        int maxLenSubstr = 0;
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(str1[i-1] == str2[j-1]){
                    temp[j] = 1 + dp[j-1];
                    maxLenSubstr = max(maxLenSubstr, temp[j]);
                }
                else temp[j] = 0;//during row transitions (dp = temp), temp retains the values computed in row i. When moving to row i+1, if a character mismatch occurs, temp[j] is not overwritten because of else continue
            }
            dp = temp;
        }

        return maxLenSubstr;
    } 
};