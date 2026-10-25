/*Given a collection of candidate numbers (candidates) and a target number (target), find all unique
 combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30*/
class Solution {
public:

void printSubseqWithSumK(int index, vector<int> &ds,set<vector<int>> &ans, vector<int> &arr, int n, int k){       
    if(k < 0)return;
        if(index >= n){
            if(k == 0){
                ans.insert(ds);//ds is a vector so set should be of vectors only
            }
            return;
        }

      
        if(k >= arr[index]){/*The condition if(k >= arr[index]) only works after sorting

Suppose

candidates = {10,1,2}
target = 3

At index 0,

k = 3
arr[0] = 10

Since 3 >= 10 is false, you never explore taking later elements (1 and 2).*/
        ds.push_back(arr[index]);
        printSubseqWithSumK(index + 1, ds, ans, arr, n, k-arr[index]);
        ds.pop_back();
        }   
        printSubseqWithSumK(index + 1, ds, ans, arr, n, k);
        return;
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int>ds;
        set<vector<int>> ans;

        sort(candidates.begin(), candidates.end());
    printSubseqWithSumK(0, ds, ans, candidates, n, target);
    vector<vector<int>>Fans;

    for(auto it : ans){
        Fans.push_back(it);
    }

    return Fans;
        
    }
};/*BRUTE FORCE:
Storing the ans vectors in a set of vectors such that it doesnt return duplicates
and finally returning it as a vector of vectors
For this, we first need to sort the given arr so as to return the ans in lexicographically correct order:
T.C. = O((2^T)*K*log(n)) + O(log n) {for operating in a set and sorting the given arr}*/