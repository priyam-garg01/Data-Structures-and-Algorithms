class Solution {
public:

    bool arrPossible(vector<int> &nums, int cows, int distance){
        int n = nums.size();
        int cowct = 1;int lastP = 0;
        for(int i = 1; i < n; i++){
            if(cowct == cows){
                return true;
            }
            if(nums[i] - nums[lastP] >= distance){
                lastP = i;
                cowct++;
            }
             if(cowct == cows){
                return true;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int maxi = INT_MIN; int mini = INT_MAX;
        /*
        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }
        */
    //    after sorting rangeM is nums[n-1] - nums[0]
            // int rangM = maxi- mini;
            int rangeM = nums[n-1] - nums[0];
           
           int low = 1; int high = rangM;
           int mid;
           while(low <= high){
            mid = (low+high)/2;
            if(arrPossible(nums, k, mid)){
                low = mid + 1;
            }
            else//if not possible 
                high = mid - 1;
           }
           //After loop ends high points to our ans and low points to ans + 1;
           return high;
       /*
        return -1;/*Suppose every distance from 1 to rangM is possible
Then loop never enters:
*/
return rangM;
    }
};