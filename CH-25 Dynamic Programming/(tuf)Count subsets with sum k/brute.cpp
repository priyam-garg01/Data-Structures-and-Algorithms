/*Given an array arr of n integers and an integer K, count the number of subsets of the given array that have a sum equal to K. Return the result modulo (109 + 7).

Example 1:
Input: arr = [2, 3, 5, 16, 8, 10], K = 10

Output: 3

Explanation: The subsets are [2, 8], [10], and [2, 3, 5].

Example 2:
Input: arr = [1, 2, 3, 4, 5], K = 5

Output: 3

Explanation: The subsets are [5], [2, 3], and [1, 4].

Now Your Turn!
Pick the correct output for the given input
Input: arr = [2, 2, 2, 2], K = 4

Constraints:
 1 <= n <= 100
1 <= arr[i] <= 103
1 <= K <= 103*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
    int countSubsetSumK(int idx, vector<int>&arr, int sum){
        // if(idx == 0){
        //     if(sum == 0)return 1;
        //     return sum == arr[0];
        // }
        // if(sum == 0)return dp[idx][sum] = 1;

        
         //Handling if arr element is zero too
    /*Removing if(sum == 0) return 1; is necessary.
Without it, when sum reaches 0 at idx > 0, the recursion continues down to idx == 0. This ensures any remaining 0 
elements are processed (since picking a 0 multiplies the number of valid subsets by 2).*/

        if(idx == 0){//Firstly idx should be checked then sum
            //Only sum == 0 base not can't satisfy the ans if the arr has '0' as element further on
            if(sum == 0 && arr[0] == 0)return 2;
            // return sum == arr[0];
            else if(sum == 0 || sum == arr[0])return 1;
            else return 0;
        }

        int notPick = countSubsetSumK(idx-1, arr, sum);

        int pick = 0;
        if(sum >= arr[idx]) pick = countSubsetSumK(idx-1, arr, sum - arr[idx]);


        return notPick + pick;
    }

	int perfectSum(vector<int>&arr, int K){
        int n = arr.size();
        int mod = 1e9 + 7;
        return countSubsetSumK(n-1, arr, K)%mod;
        
	}
};//T.C. = O(2^N), S.C. = O(N)