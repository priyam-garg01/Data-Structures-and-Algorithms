#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:

        int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {
            vector<int> dp(W+1, 0);
            // if(W >= wt[0])dp[0][wt[0]] = val[0];Incomplete base case
            //Base case should state that for evry wt >= wt[0] that lies at index 0 it return the val of item at index 0
            for(int w = wt[0]; w <= W; w++)dp[w] = val[0];

//We can further optimize our space to O(W)-> we start from reverse side of wt ct; We observe that we need dp[w]that is wt from the prev row and dp[w-wt[i]] which also stored in prev row in the next parts which remain same and isn't disturbed by us
            for(int i = 1; i < n; i++){
                for(int w = W; w >= 0; w--){
                    int notPick = dp[w];

                    int pick = 0;
                    if(w >= wt[i])pick = val[i] + dp[w-wt[i]];

                    dp[w] = max(pick, notPick); 
                }
            }

            return dp[W];
        }
};//T.C. = O(N*W), S.C. = O(W)  