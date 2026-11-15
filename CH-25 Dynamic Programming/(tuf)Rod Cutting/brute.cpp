/*Given a rod of length N inches and an array price[] where price[i] denotes the value of a piece of rod of length i inches (1-based indexing). Determine the maximum value obtainable by cutting up the rod and selling the pieces. Make any number of cuts, or none at all, and sell the resulting pieces.

Example 1:
Input: price = [1, 6, 8, 9, 10, 19, 7, 20], N = 8

Output: 25

Explanation: Cut the rod into lengths of 2 and 6 for a total price of 6 + 19= 25.

Example 2:
Input: price = [1, 5, 8, 9], N = 4

Output: 10

Explanation: Cut the rod into lengths of 2 and 2 for a total price of 5 + 5 = 10.

Now Your Turn!
Pick the correct output for the given input
Input: price = [5, 5, 8, 9, 10, 17, 17, 20], N = 8
38 40 45 42
Constraints:
1 ≤ N ≤ 1000
1 ≤ price[i] ≤ 105*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int maxCutProfit(int idx, int N, vector<int>& price){
        if(idx == 0){
            if(N == 0)return 0;
            if(N >= 1)return price[0]*N;
        
        }

        int notCut = maxCutProfit(idx-1, N, price);

        int Cut = 0;
        if(N >= idx+1)Cut = price[idx] + maxCutProfit(idx, N-(idx+1), price);

        return max(Cut, notCut);
    }
    
    int rodCutting(vector<int> price, int n) {
        
        return maxCutProfit(n-1, n, price);
    }
};

