#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:

	int minDifference(vector<int>&arr, int n)  { 
        int sum = 0; 
        for(int i = 0; i < n; i++){
            sum += arr[i];
        }
        int target = 0;
        if(sum%2 == 0)target = sum/2;
        else target = sum/2+1;
        vector<int> dp(sum+1, 0);
        vector<int> temp(sum+1, 0);
        dp[0] = 1;
        temp[0] = 1;
        
        if(sum >= arr[0])dp[arr[0]] = 1;

        for(int i = 1; i < n; i++){
            for(int t = 1; t <= sum; t++){
                bool notPick = dp[t];

                bool Pick = false;
                if(t >= arr[i]) Pick = dp[t-arr[i]];

                temp[t] = Pick || notPick;
            }
            dp = temp;
        }


        for(int t = target; t <= sum; t++){
            if(dp[t] == 1)return t-(sum-t);
        }

	} 
};//T.C. = O(N*SUM) + O(Sum/2), S.C. = O(2*Sum);