#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    
    
    int stockBuySell(vector<int> arr, int n){
        int bestBuy = arr[0];
        int maxP = 0;
        int profit = 0;

        for(int i = 1; i < n; i++){
            profit = arr[i] - bestBuy;
            if(profit > maxP){
                maxP = profit;
            }
            bestBuy = min(bestBuy, arr[i]);//Before moving to next we see the min of thr prev and curr
        }
        return maxP;
    }
};