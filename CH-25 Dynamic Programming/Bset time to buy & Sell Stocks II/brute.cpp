/*You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 

Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104*/
#include<bits/stdc++.h>
using namespace std;
class Solution {//Wrong Sol
public:
    int allProfits(int i, int buy, vector<int>& prices, int n){
        if(i >= n)return 0;

        //2 paths if already bounght then only selling occurs else only buying occurs as only 1 share can be kept at a time
        //Buying
        if(buy == -1)return max(allProfits(i+1, buy, prices, n), allProfits(i+1, prices[i], prices, n));//As the share price could be zero

        //Selling
        return max(allProfits(i+1, buy, prices, n), prices[i] - buy + allProfits(i+1, -1, prices, n));
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //We can buy and sell multiple times
        return allProfits(0, -1, prices, n);
    }
};
class Solution {
public:
        /*Passing prices[i] as buy creates up to N unique state values instead of 2 binary states (1 = can buy, 0 = can sell)
        Mistake i did*/
        int allProfits(int i, int buy, vector<int>& prices, int n, vector<int>& dp){
        if(i >= n)return 0;

        //Buying
        if(buy == 0)return dp[i] = max(allProfits(i+1, buy, prices, n, dp), allProfits(i+1, 1, prices, n, dp)-prices[i]);

        //Selling
        return dp[i] = max(allProfits(i+1, buy, prices, n, dp), prices[i] + allProfits(i+1, 0, prices, n, dp));
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //We can buy and sell multiple times
        vector<int> dp(n, -1);
        return allProfits(0, 0, prices, n, dp);
    }
};/*Brute: 2 cases each in buying in selling and the base case when arr has no element left to check
T.C. = O(2^(N)), S.C. = O(N)*/