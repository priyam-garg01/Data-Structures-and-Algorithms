#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//Wrong: Lat idx has to be 0 as if no Lis is formed with len > 1 ans = 1
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n, -1);
        for(int i = 0; i < n; i++)hash[i] = i;
        
        int maxi = 1;
        int lastIdx = -1;
        for(int i = 1; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i] && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIdx = i;
            }
        }
        int ans = maxi;
        vector<int> Lis(ans, -1);
        Lis[maxi-1] = nums[lastIdx];
        maxi--;
        while(hash[lastIdx] != lastIdx){
            lastIdx = hash[lastIdx];
            Lis[maxi-1] = nums[lastIdx];
            maxi--;
        }
        return ans;
    }
};
/*Tabulation Algorithm with Printing Lis: Tabulation Algorithm: Initialize all as 1 in the dp array, as min LIS will be 1 (itself). Move through the array and take prev till i-1 if the len of the current element can be incremented (nums>nums[prev] && the curr len is lesser than dp[prev] + 1), store it in a max var, and at the end put the maximum len in dp. At last, find the max of all.
Printing: Use a hash arr and initiate the indices not the prev indices where the max finally gets changed after 1 loop of i
T.C. = O(N*N +N), S.C. = O(2N)*/
class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n, -1);
        for(int i = 0; i < n; i++)hash[i] = i;
        
        int maxi = 1;
        int lastIdx = 0;
        for(int i = 1; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i] && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIdx = i;
            }
        }
        int ans = maxi;
        vector<int> Lis(ans, -1);
        Lis[maxi-1] = nums[lastIdx];
        maxi--;
        while(hash[lastIdx] != lastIdx){
            lastIdx = hash[lastIdx];
            Lis[maxi-1] = nums[lastIdx];
            maxi--;
        }
        return ans;
    }
};