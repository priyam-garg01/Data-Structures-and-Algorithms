#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(k, 0);
        
        for(int i = 1; i < n; i++){
            int idx = 1;
            int mini = 1e9;
            while(i-idx >= 0 && idx<=k){
                int jump = abs(heights[i]-heights[i-idx])+dp[(i-idx)%k];
                mini = min(jump, mini);
                idx++;
            }
            dp[i%k] = mini;
        }
        return dp[(n-1)%k];
    }//T.C. = O(N*K), S.C. = O(K)
};/*Earlier errors
Out of bounds access: dp[i - idx] assumes dp retains full history of size N. Erasing elements changes dp indices.
Performance degradation: dp.erase(dp.begin()) takes O(K) time per shift, making overall time complexity O(N×K*K)
Incorrect return value: return dp[k-1] does not access the final answer at index N−1.*/

/*Also in the worst case k --> N so no use*/