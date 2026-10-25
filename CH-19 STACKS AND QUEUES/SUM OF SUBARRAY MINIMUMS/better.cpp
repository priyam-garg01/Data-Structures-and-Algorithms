class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int total = 0;
        int mod = int(1e9 + 7);
        for(int i = 0; i < n; i++){
                int mini = arr[i];
            for(int j = i; j < n; j++){
                mini = min(mini, arr[j]);
                total = (total+mini)%mod;
            }
        }
        return total;
    }
};/*BETTER APPROACH: T.C. = O(N2)*/