#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        //Longest Increasing Subsequence With Multiple K or Longets Decreasing Subsequence with Multiple K
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        vector<int> dp(n, 1);
        vector<int> hash(n, 0);//For printing the Lis
        for(int i = 0; i < n; i++)hash[i] = i;

        int maxi = 1;
        int lastIdx = 0;
        for(int i = 1; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(temp[i]%temp[prev] == 0 && dp[prev] + 1 > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIdx = i;
            }
        }

        vector<int> Lis(maxi, -1);
        int ind = maxi-1;
        Lis[ind] = temp[lastIdx];
        ind--;
        while(hash[lastIdx] != lastIdx){
            lastIdx = hash[lastIdx];
            Lis[ind] = temp[lastIdx];
            ind--;
        }
        return Lis;

    }
};/*Tabulation Algorithm for printing Lis
T.C. = O(N*N + N), S.C. = O(3N)*/