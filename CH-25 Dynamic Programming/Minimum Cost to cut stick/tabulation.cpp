#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int miniCost(int i, int j, vector<int>&cuts, vector<vector<int>>& dp){
        if(i > j)return 0;

        if(dp[i][j] != -1)return dp[i][j];
        int mini = 1e9;

        for(int k = i; k <= j; k++){
            int cut = cuts[j+1] - cuts[i-1];
            cut += miniCost(i, k-1, cuts, dp) + miniCost(k+1, j, cuts, dp);
            mini = min(mini, cut);
        }

        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        int size = cuts.size();
        sort(cuts.begin(), cuts.end());//Sorting is necessary to get the length of the string right as all left elements should be less than right
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        vector<vector<int>> dp(size+2, vector<int>(size+1,0));

        for(int i = size; i >= 1; i--){
            for(int j = 1; j <= size; j++){
                if(i > j)continue;
                int mini = 1e9;
                for(int k = i; k <= j; k++){
                    int cut = cuts[j+1] - cuts[i-1];
                    cut += dp[i][k-1] + dp[k+1][j];
                    mini = min(mini, cut);
            }
            dp[i][j] = mini;
            }
        }


        return dp[1][size];
    }
};/*Tabulation: Just Reverse the indices with the base case statisfying:
T.C. = O(N^3), S.C. = O(N^2)*/