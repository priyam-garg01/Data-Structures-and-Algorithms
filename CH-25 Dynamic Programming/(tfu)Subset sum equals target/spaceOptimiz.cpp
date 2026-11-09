#include<bits/stdc++.h>
using namespace std;
class Solution{   
public:
    
    bool isSubsetSum(vector<int>arr, int target){
        int n = arr.size();
        
        vector<int> dp(target+1, 0);
        //Since you are using tabulation, you calculate every state iteratively. You don't need -1 to indicate an uncomputed state.
        vector<int> temp(target+1, 0);
      
        dp[0] = 1;//For any val of index and target zero we get true 
        temp[0] = 1;
        //For any target val at index 0 we return arr[0] == target 
        if(arr[0] <= target) {
                dp[arr[0]] = 1;
        }

        for(int i = 1; i < n; i++){
            for(int t = 1; t <= target; t++){
                 //Take
                bool pick = false;
                if(t >= arr[i])pick = dp[t-arr[i]];

                //Dont Take
                bool notPick = false;
                notPick = dp[t];

                temp[t] = (pick || notPick);
            }
            dp = temp;
        }
        
        return dp[target];
    }
};//T.C. = O(N*TARGET), S.C. = O(2*TARGET)