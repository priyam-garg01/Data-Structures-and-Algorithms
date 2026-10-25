/*The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

 

Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
Example 3:

Input: n = 3, k = 1
Output: "123"
 

Constraints:

1 <= n <= 9
1 <= k <= n!*/
class Solution {
public:

void recurPermute(int index, vector<string> &ans, vector<char> &nums, int n){
    if(index == n){
            string s;//s[i] is out of bounds as s has zero size
            
        for(char c : nums){
            s.push_back(c);
        }
        ans.push_back(s);
        return;
    }

    for(int i = index; i < n; i++){
        swap(nums[index], nums[i]);
        recurPermute(index + 1, ans, nums, n);
        swap(nums[index], nums[i]);
    }
}
    string getPermutation(int n, int k) {
        //BRUTE FORCE: Find all permutations with in a ds and sort it, the k-1th index string will be our answer
        vector<char> nums;
        for(int i = 1; i <= n; i++){
            nums.push_back(i + '0');
        }
        //Here we get our nums vector
        vector<string> ans;
        //Via recursion we will mold nums and put it in the ans
        recurPermute(0, ans, nums, n);

        //last step to sort the ans in lexicographical order
        sort(ans.begin(), ans.end());
        return ans[k-1];
    }
};/*//BRUTE FORCE: Find all permutations with in a ds and sort it, the k-1th index string will be our answer
T.C. = O(N) + O((n!)*n), S.C. = O(N){NUMS ARR} + O(N){RECURSION STACK SPACE}*/