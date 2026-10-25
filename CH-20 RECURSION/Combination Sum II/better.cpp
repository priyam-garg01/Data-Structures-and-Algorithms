class Solution {
public:

void printSubseqWithSumK(int index, vector<int> &ds, vector<vector<int>> &ans, vector<int> &arr, int n, int k){    
            if(k == 0){
                ans.push_back(ds);
            return;
            }

            for(int i = index; i < n; i++){
                if(i > index && arr[i] == arr[i-1])continue;//as we dont want to pick the same elements
                if(arr[i] > k){
                    break;
                }
        ds.push_back(arr[i]);
        printSubseqWithSumK(i + 1, ds, ans, arr, n, k-arr[i]);
        ds.pop_back();
            }
        
        return;
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int>ds;
        vector<vector<int>> ans;

        sort(candidates.begin(), candidates.end());
    printSubseqWithSumK(0, ds, ans, candidates, n, target);
    
        return ans;
    }
};/*We will check our pick for each index element at every go through the for loop and if it's equal to the previous element that is taken, we do not consider it as our pick
i > index resembles that whatever we are not picking it for the first time
T.C. = O((2^n)*k) {As there are approx. n choices to pick the element from at every stage fromt the loop}
S.C. = O(K*X)*/