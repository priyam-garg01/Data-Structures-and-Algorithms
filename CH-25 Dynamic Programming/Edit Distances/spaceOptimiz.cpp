#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<int> dp(n2+1, 0);
        vector<int> temp(n2+1, 0);
        // for(int i = 0; i <= n1; i++)dp[i][0] = i;
        // dp[0][0] = 0;

        for(int j = 0; j <= n2; j++)dp[j] = j;//For i = 0

        // temp[0] = 1;//i = 1
        for(int i = 1; i <= n1; i++){
            temp[0] = i;
            for(int j = 1; j <= n2; j++){
                if(word1[i-1] == word2[j-1])temp[j] = dp[j-1];
        
                else{
                    int del = 1 + dp[j];
                    int insert = 1 + temp[j-1];
                    int replace = 1 + dp[j-1];
                    temp[j] = min(del, min(insert, replace));
                }
            }
            dp = temp;
        }

        return dp[n2];
    }
};