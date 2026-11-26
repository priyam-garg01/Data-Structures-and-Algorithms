/*Given an array arr of n integers, the task is to find the length of the longest bitonic sequence. A sequence is considered bitonic if it is strictly increasing, strictly decreasing, or strictly increases and then strictly decreases.. The sequence does not have to be contiguous.

Example 1:
Input: arr = [5, 1, 4, 2, 3, 6, 8, 7]

Output: 6

Explanation: The longest bitonic sequence is [1, 2, 3, 6, 8, 7] with length 6.

Example 2:
Input: arr = [10, 20, 30, 40, 50, 40, 30, 20]

Output: 8

Explanation: The entire array is bitonic, increasing up to 50 and then decreasing.

Now Your Turn!
Pick the correct output for the given input
Input: arr = [12, 11, 10, 15, 18, 17, 16, 14]
Constraints:
1 <= arr.length <= 103
-106<= arr[i] <= 106*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int LongestBitonicSequence(vector<int> arr) {
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int> dpR(n, 1);
       
        for(int i = 1; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(arr[i] > arr[prev] && dp[i] < dp[prev] + 1){
                    dp[i] = dp[prev] + 1;
                }
            }
        }
        for(int i = n-1; i >= 0; i--){
            for(int prev = n-1; prev > i; prev--){
                if(arr[i] > arr[prev] && dpR[i] < dpR[prev] + 1){
                    dpR[i] = dpR[prev] + 1;
                }
            }
        }

        vector<int> bitonic(n, 1);
        int maxi = 1;
        for(int i = 0; i < n; i++){
            bitonic[i] = dp[i] + dpR[i];
            maxi = max(maxi, bitonic[i]);
        }

        return maxi-1;//As the bridging element having the max sum is counted twice
        /*int maxi = 1;
        for(int i = n-1; i >= 0; i--){
            for(int prev = n-1; prev > i; prev--){
                if(arr[i] > arr[prev] && dpR[i] < dpR[prev] + 1){
                    dpR[i] = dpR[prev] + 1;
                }
            }
            maxi = max(maxi, dp[i]+dpR[i]-1);
        }
        return maxi;*/
    }
};//T.C. = O(N*N), S.C. = O(3N)
