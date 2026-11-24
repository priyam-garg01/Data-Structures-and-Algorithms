#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //We can buy and sell multiple times
        vector<int> dp(2, 0);
        vector<int> temp(2, 0);
        
        int buy = 0;
        dp[0] = 0;
        dp[1] = 0;
        
        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy < 2; buy++){
                //Buying
                if(buy == 0)temp[buy] = max(dp[buy], dp[1]-prices[i]);

                //Selling
                else temp[buy] = max(dp[buy], prices[i] +dp[0]);
            }
            dp = temp;
        }
        return dp[0];
    }
};/*Space Optimiz S.C. = O(2*2) = O(1)*/

class Solution {
public:
     
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // vector<int> dp(2, 0);
        // vector<int> temp(2, 0);

        int aheadNotBuy = 0; // dp[0] = 0;
        int aheadBuy = 0;// dp[1] = 0;

        int currNotBuy = 0; 
        int currBuy = 0; 

        for(int i = n-1; i >= 0; i--){
                currBuy = max(aheadBuy, aheadNotBuy-prices[i]);
                currNotBuy = max(aheadNotBuy, prices[i] + aheadBuy);//Due to changing my view of buy that is buy = 0 we have to buy and buy = 1 already bought the at somplaces positions of aheadNotBuy and aheadBuy changes
                aheadBuy = currBuy;
                aheadNotBuy = currNotBuy;
            }
        return aheadBuy;
    }
};/*Space Optimiz using variables*/