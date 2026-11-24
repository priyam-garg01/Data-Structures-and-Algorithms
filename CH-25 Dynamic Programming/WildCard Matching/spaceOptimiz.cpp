#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkMatch(int i, int j, string s, string t, vector<vector<int>>& dp){
        if(i == 0 && j == 0)return true;
        if(i == 0 && j > 0){
            // if(j == 0 && t[j] == '*')return true;
            // return false;It may have all stars
            for(int k = j; k > 0; k--){
                if(t[k-1] != '*')return false;
            }
            return true;
        }
        if(i > 0 && j == 0)return false;
        if(dp[i][j] != -1)return dp[i][j];

        if(t[j-1] == '?' || s[i-1] == t[j-1])return dp[i][j] = checkMatch(i-1, j-1, s, t, dp);
        if(t[j-1] == '*')return dp[i][j] = checkMatch(i-1, j, s, t, dp)|| checkMatch(i, j-1, s, t, dp);//delete char and keep star OR delete star for nothing

        return dp[i][j] = false;//if none of the above cases are there
    }

    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        vector<int> dp(n2+1, 0);
        vector<int> temp(n2+1, 0);
        dp[0] = 1;
       
        for(int j = 1; j <= n2; j++){
            if(p[j-1] != '*'){
                //Whenever at any index star is not there we initiate the further values in the dp table to zero
                break;
            }
            else dp[j] = 1;
        }
        

        // for(int i = 1; i <= n1; i++)dp[i][0] = 0; --> temp[0] = 0;


        for(int i = 1; i <= n1; i++){
            temp[0] = 0;//First element of every row is zero
            for(int j = 1; j <= n2; j++){
                if(p[j-1] == '?' || s[i-1] == p[j-1])temp[j] = dp[j-1];

                else if(p[j-1] == '*')temp[j] = (dp[j] || temp[j-1]);

                else temp[j] = 0;//if none of the above cases are there
            }
            dp = temp;
        }

        return dp[n2];
    }
};