/*Given two integer arrays, val and wt, each of size n, which represent the values and weights of n items respectively, and an integer W representing the maximum capacity of a knapsack, determine the maximum value achievable by selecting a subset of the items such that the total weight of the selected items does not exceed the knapsack capacity W.

Each item can either be picked in its entirety or not picked at all (0-1 property). The goal is to maximize the sum of the values of the selected items while keeping the total weight within the knapsack's capacity.

Example 1:
Input: val = [60, 100, 120], wt = [10, 20, 30], W = 50

Output: 220

Explanation: Select items with weights 20 and 30 for a total value of 100 + 120 = 220.

Example 2:
Input: val = [10, 40, 30, 50], wt = [5, 4, 6, 3], W = 10

Output: 90

Explanation: Select items with weights 4 and 3 for a total value of 40 + 50 = 90.

Constraints:
1 ≤ N ≤ 500
1 ≤ W ≤ 1000
1 ≤ wt[i] ≤ 500
1 ≤ val[i] ≤ 500*/

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int maximizeSum(int idx, vector<int>& wt, vector<int>& val, int W){
            if(idx == 0){
                if(W >= wt[0])return val[0];
                return 0;
            }
            if(W == 0)return 0;

            int notPick = maximizeSum(idx-1, wt, val, W);

            int pick = 0;
            if(W >= wt[idx])pick = val[idx] + maximizeSum(idx-1, wt, val, W-wt[idx]);

            return max(pick, notPick); 
        }

        int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {

             return maximizeSum(n-1, wt, val, W);
        }
};//T.C. = O(2^N), S.C. = O(N)
