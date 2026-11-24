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
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return checkMatch(n1, n2, s, p, dp);
    }
};