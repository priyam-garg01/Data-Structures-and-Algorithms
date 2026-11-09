#include<bits/stdc++.h>
using namespace std;
class Solution{   
public:
    
    bool isSubsetSum(vector<int>arr, int target){
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        //Since you are using tabulation, you calculate every state iteratively. You don't need -1 to indicate an uncomputed state.
        for(int i = 0; i < n; i++){
            dp[i][0] = 1;//For any val of index and target zero we get true 
        }


        //For any target val at index 0 we return arr[0] == target 
        if(arr[0] <= target) {
                dp[0][arr[0]] = 1;
            }

        for(int i = 1; i < n; i++){
            for(int t = 1; t <= target; t++){
                 //Take
                bool pick = false;
                if(t >= arr[i])pick = dp[i-1][t-arr[i]];

                //Dont Take
                bool notPick = false;
                notPick = dp[i-1][t];

                dp[i][t] = (pick || notPick);
            }
        }
        
        return dp[n-1][target];
    }
};//T.C. = O(N*TARGET), S.C. = O(N*TARGET)