class Solution {
public:
    bool isPossible(vector<int> &arr, int subArrs, int sumP){
        int n = arr.size();
        int ctSub = 1;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(sum > sumP){
                ctSub++;sum = arr[i];
            }
            if(ctSub > subArrs){
                return false;
            }
        }
            return true;
    }
    int largestSubarraySumMinimized(vector<int> &a, int k) {
        int n = a.size();
        //Range of answers will be from maximum element to sum
        int maxi = INT_MIN; int sum = 0;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, a[i]);
            sum += a[i];
        }

        for(int i = maxi; i <= sum; i++){
            if(isPossible(a, k, i)){
                return i;
            }
        }
        return -1;
    }
};