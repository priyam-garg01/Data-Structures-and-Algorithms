/*Given an array arr of n integers and an integer diff, count the number of ways to partition the array into two subsets, S1 and S2, such that:

sum(S1) ≥ sum(S2)
sum(S1) − sum(S2) = diff
Here, sum(S1) and sum(S2) denote the sums of the elements in the respective subsets.

Return the result modulo 109 + 7.

Note: A partition means that the union of S1 and S2 is the original array, and no element is left out or used twice — every element of the array belongs to exactly one of the two subsets.

Example 1:
Input: arr = [1, 1, 2, 3], diff = 1

Output: 3

Explanation: The subsets are [1, 2] and [1, 3], [1, 3] and [1, 2], [1, 1, 2] and [3].

Example 2:
Input: arr = [1, 2, 3, 4], diff = 2

Output: 2

Explanation: The subsets are [1, 3] and [2, 4], [1, 2, 3] and [4].

Now Your Turn!
Pick the correct output for the given input
Input: arr = [5, 2, 6, 4], diff = 3

Constraints:
1 <= n <= 200
0 <= d <= 104
0 <= arr[i] <= 50*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int mod = 1e9+7;
    int ctPartition(int idx, int target, vector<int>& arr){
        if(idx == 0){
            if(target == 0 && arr[0] == 0)return 2;
            else if(target == 0 || target == arr[0])return 1;
            return 0;
        }
    
        int notPick = ctPartition(idx-1, target, arr);

        int pick = 0;
        if(target >= arr[idx])pick = ctPartition(idx-1, target-arr[idx], arr);

        return (pick + notPick)%mod; 
    }
    int countPartitions(int n, int diff, vector<int>& arr) {
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
        }
        //we need s1 > s2 ; s1 = sum - s2 
        //also s1 - s2 = D => sum - 2*s2 = D => s2 = (sum-D)/2
        //Hence we need to find subsets that have sum = s2;
        int target = (sum-diff)/2;
        if((sum-diff)%2 != 0 || target < 0)return 0;
        
        return ctPartition(n-1, target, arr);
    }
};