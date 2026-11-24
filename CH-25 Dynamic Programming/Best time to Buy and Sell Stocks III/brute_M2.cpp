#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int profits(int i, int t, vector<int>& prices, int n){
        if(i == n || t == 4)return 0;

        int profit = 0;
        //Buying
        if(t%2 == 0)profit = max(profits(i+1, t, prices, n), profits(i+1, t+1, prices, n)-prices[i]);

        //Selling
        else profit = max(profits(i+1, t, prices, n), profits(i+1, t+1, prices, n)+prices[i]);
        return profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int transaction = 0;//Transaction vary from 0-3 if 4 then return 0
        return profits(0, transaction, prices, n);
    }
};/*M-2: Taking transaction as 1, 2, 3, 4 for buying and selling*/