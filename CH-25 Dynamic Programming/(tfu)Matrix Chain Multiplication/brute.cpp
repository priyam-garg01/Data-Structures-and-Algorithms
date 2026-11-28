/*Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices. In other words, determine where to place parentheses to minimize the number of multiplications.

Given an array nums of size n. Dimension of matrix Ai ( 0 < i < n ) is nums[i - 1] x nums[i].Find a minimum number of multiplications needed to multiply the chain.

Example 1:
Input : nums = [10, 15, 20, 25]

Output : 8000

Explanation : There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.

If we multiply in order- A1*(A2*A3), then number of multiplications required are 11250.

If we multiply in order- (A1*A2)*A3, then number of multiplications required are 8000.

Thus minimum number of multiplications required is 8000.

Example 2:
Input : nums = [4, 2, 3]

Output : 24

Explanation : There is only one way to multiply the chain - A1*A2.

Thus minimum number of multiplications required is 24.

Now Your Turn!
Pick the correct output for the given input
Input : nums = [1, 2, 3, 4, 5]
36 38 40 42
Constraints:
2 <= n <= 100
1 <= nums[i] <= 100*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
        int minMutilp(int i, int j, vector<int>& nums){
            if(i == j)return 0;//No multiplications for an array
            int mini = INT_MAX;
            for(int k = i; k < j; k++){//K remains till j-1 as k+1 should not exceed arr len and also funct(j, j)will return zero while funct(j+1, j)might cause arrayIndexOutofBounds Error
                int steps = nums[i-1]*nums[k]*nums[j];//(rows(stMat))*(insection OR Partition index)*(col(endMat))
                steps += minMutilp(i, k, nums) + minMutilp(k+1, j, nums);
                mini = min(mini, steps);
            }

            return mini;
        }

		int matrixMultiplication(vector<int>& nums){
            int n= nums.size();
            
            return minMutilp(1, n-1, nums);
    	}
};/*Just say its exponential O(2^N)(exponential), specifically proportional to the N-th Catalan number, O((4^N)/N^1.5)*/
