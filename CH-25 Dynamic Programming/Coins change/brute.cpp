/*Given an integer array of coins representing coins of different denominations and an integer amount representing a total amount of money. Return the fewest number of coins that are needed to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1. There are infinite numbers of coins of each type

Example 1:
Input: coins = [1, 2, 5], amount = 11

Output: 3

Explanation: 11 = 5 + 5 + 1. We need 3 coins to make up the amount 11.

Example 2:
Input: coins = [2, 5], amount = 3

Output: -1

Explanation: It's not possible to make amount 3 with coins 2 and 5. Since we can't combine the coin 2 and 5 to make the amount 3, the output is -1.

Now Your Turn!
Pick the correct output for the given input
Input: coins = [10], amount = 5


-1

0
Still unsure what the problem is asking ?

Let’s go through a few more examples, step by step, to make it clearer.

Constraints:
n=number of distinct denominations
1 <= n <= 100
1 <= coins[i], amount <= 103*/
#include<bits/stdc++.h>/
using namespace std;
class Solution{
	public:
    int ctPossibleComb(int idx, vector<int>& coins,int target){
        if(idx == 0){
            if(target%coins[0] == 0)return target/coins[0];
            return 1e9;
        }
        if(target == 0)return 0;

        int notPick = ctPossibleComb(idx-1, coins, target);

        int pick = 1e9;
        // if(target >= coins[idx])pick = target/coins[idx] + ctPossibleComb(idx-1, coins, target%coins[idx]);
        //If we take the max possible val from a coin it may be the case that the amount which could be filled if we had taken less denominations is not fullfilled now
        if(target >= coins[idx])pick = 1 + ctPossibleComb(idx, coins, target-coins[idx]);

        return min(pick, notPick);
    }

	int MinimumCoins(vector<int>& coins, int amount) {
        int n = coins.size();
        int target = amount;
        int ct = ctPossibleComb(n-1, coins, target);
        if(ct == 1e9)return -1;
        return ct;
    }
};//T.C. = O(2^TARGET), S.C. = O(TARGET)