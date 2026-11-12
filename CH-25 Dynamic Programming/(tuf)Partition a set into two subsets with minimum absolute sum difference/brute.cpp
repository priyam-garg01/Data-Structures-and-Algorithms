/*Given an array arr of n integers, partition the array into two subsets such that the absolute difference between their sums is minimized.

Example 1:
Input: arr = [1, 7, 14, 5]

Output: 1

Explanation: The array can be partitioned as [1, 7, 5] and [14], with an absolute difference of 1.

Example 2:
Input: arr = [3, 1, 6, 2, 2]

Output: 0

Explanation: The array can be partitioned as [3, 2, 2] and [6, 1], with an absolute difference of 0.

Now Your Turn!
Pick the correct output for the given input
Input: arr = [2, 2, 2, 9]
Constraints:
1 ≤ n * sum of array elements ≤ 106
0 < arr[i] <= 104*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:

    bool getTarget(int idx, int target, vector<int>& arr){
        if(target == 0)return true;
        if(idx == 0)return target == arr[0];

        bool notPick = getTarget(idx-1, target, arr);

        bool Pick = false;
        if(target >= arr[idx]) Pick = getTarget(idx-1, target-arr[idx], arr);

        return Pick || notPick;
    }

	int minDifference(vector<int>&arr, int n)  { 
        int sum = 0; 
        for(int i = 0; i < n; i++){
            sum += arr[i];
        }
       
        int target = 0;//The min diff can be zero; iterating from target to sum if there is a true val returned we return the diff
        if(sum%2 == 0)target = sum/2;
        else target = sum/2+1;
        
        for(int t = target; t <= sum; t++){
            bool val =  getTarget(n-1, t, arr);
            if(val)return t-(sum-t);
        }
	} 
};/*T.C. = O(sum*2^N) , S.C. = O(sum/2 * N)*/
