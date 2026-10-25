/*You are given an array target of n integers. From a starting array arr consisting of n 1's, you may perform the following procedure :

let x be the sum of all elements currently in your array.
choose index i, such that 0 <= i < n and set the value of arr at index i to x.
You may repeat this procedure as many times as needed.
Return true if it is possible to construct the target array from arr, otherwise, return false.

 

Example 1:

Input: target = [9,3,5]
Output: true
Explanation: Start with arr = [1, 1, 1] 
[1, 1, 1], sum = 3 choose index 1
[1, 3, 1], sum = 5 choose index 2
[1, 3, 5], sum = 9 choose index 0
[9, 3, 5] Done
Example 2:

Input: target = [1,1,1,2]
Output: false
Explanation: Impossible to create target array from [1,1,1,1].
Example 3:

Input: target = [8,5]
Output: true
 

Constraints:

n == target.length
1 <= n <= 5 * 104
1 <= target[i] <= 109*/
class Solution {
public:

    bool backtrack(vector<int>& curr, vector<int> target, long long sum){
        if(curr == target)return true;

        for(int i = 0; i < curr.size(); i++){
            if(sum > target[i])continue;

            int oldVal = curr[i];
            curr[i] = sum;

            if(backtrack(curr, target, sum - oldVal + sum))return true;

            curr[i] = oldVal;//backtrack
        }
        return false;
    }
    bool isPossible(vector<int>& target) {
        //We are given an arr consisting of n 1's we need to sum the n 1's consecutively such that we create the target array
        
        /*we store the elements of target in a map or set to use the find function and keep summing the n numbers till we get our target arr or the sum element doesnt exist in the target array

Doesn't Work as we can make the target in multiple attempts not by just adding one time*****/

        /*BRUTE: Start with A = [1, 1, ..., 1]. At each step, calculate the sum of all elements in A. Try replacing each index with sum and recursively check if any path matches target.*/
    
        int n = target.size();
        if(n == 1)return target[0] == 1;

        vector<int> curr(n, 1);
        long long sum = n;

        return backtrack(curr, target, sum);
    
    }
};