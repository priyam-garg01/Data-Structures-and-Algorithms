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
        int low = maxi; int high = sum; int mid;

        while(low <= high){
            mid = low + (high-low)/2;
            if(isPossible(a, k, mid)){
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return low;
    }
};