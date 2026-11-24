/*You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

Constraints:

1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int profits(int i, int t, vector<int>& prices, int n, int k){
        if(i == n || t == 2*k)return 0;
        
        
        int profit = 0;
        //Buying
        if(t%2 == 0)profit = max(profits(i+1, t, prices, n, k), profits(i+1, t+1, prices, n, k)-prices[i]);
        //Selling
        else profit = max(profits(i+1, t, prices, n, k), profits(i+1, t+1, prices, n, k)+prices[i]);

        return profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int transactions = 2*k;

        return profits(0, 0, prices, n, k); 
    }
};