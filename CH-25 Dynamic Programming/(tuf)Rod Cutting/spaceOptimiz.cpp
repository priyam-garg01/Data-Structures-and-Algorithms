#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int rodCutting(vector<int> price, int n) {
         vector<int> dp(n+1, 0);
         vector<int> temp(n+1, 0);
        for(int i = 1; i <= n; i++){
            dp[i] = price[0]*i;
        }

        for(int idx = 1; idx < n; idx++){
            for(int t = 0; t <= n; t++){
                int notCut = dp[t];

                int Cut = 0;
                if(t >= idx+1)Cut = price[idx] +temp[t-(idx+1)];

                temp[t] = max(Cut, notCut);
            }
            dp = temp;
        }

        return dp[n];
    }
};
class Solution{
  public:
    int rodCutting(vector<int> price, int n) {
         vector<int> dp(n+1, 0);
        for(int i = 1; i <= n; i++){
            dp[i] = price[0]*i;
        }

        for(int idx = 1; idx < n; idx++){
            for(int t = 0; t <= n; t++){
                int notCut = dp[t];

                int Cut = 0;
                if(t >= idx+1)Cut = price[idx] +dp[t-(idx+1)];

                dp[t] = max(Cut, notCut);
            }
        }

        return dp[n];
    }
};//Most optimal;Since prev elem are used which are of next row that is updated in the cut part we can use 1 array only