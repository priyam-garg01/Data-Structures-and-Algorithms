#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int numMatches(int i, int j, string s, string t, vector<vector<int>>& dp){
        if(i < 0 || j < 0)return 0;
        // if(j == 0){//if string is matched early it lefts behind all other which could have been added
        //     if(i >= 0 && s[i] == t[j])return 1;
        //     return numMatches(i-1, j, s, t);
        // }
        if(dp[i][j] != -1)return dp[i][j];
        int pick = 0;
        if(s[i] == t[j]){
            if(j == 0)pick = 1;
            pick += numMatches(i-1, j-1, s, t, dp);
        }
        int notPick = numMatches(i-1, j, s, t, dp);

        return dp[i][j] = pick + notPick;
    }

    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        //To find the number of distinct times string t appears in s
        if(n > m)return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return numMatches(m-1, n-1, s, t, dp);
        
    }
};
//1-based indexing
class Solution {
public:

    int numMatches(int i, int j, string s, string t, vector<vector<int>>& dp){
        if(i == 0 || j == 0)return 0;
        // if(j == 0){//if string is matched early it lefts behind all other which could have been added
        //     if(i >= 0 && s[i] == t[j])return 1;
        //     return numMatches(i-1, j, s, t);
        // }
        if(dp[i][j] != -1)return dp[i][j];
        int pick = 0;
        if(s[i-1] == t[j-1]){
            if(j-1 == 0)pick = 1;
            pick += numMatches(i-1, j-1, s, t, dp);
        }
        int notPick = numMatches(i-1, j, s, t, dp);

        return dp[i][j] = pick + notPick;
    }

    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        //To find the number of distinct times string t appears in s
        if(n > m)return 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return numMatches(m, n, s, t, dp);
        

    }
};