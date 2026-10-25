/*Check the range in which answer would lie given that min of two cows are to be positioned 
1)Sort the array and appyly logic foe searching linearly from distance = 1 to max of range
NOTE: finally return rangM (for if the loop finishes with all the distances ranging till rangM) */ 


class Solution {
public:

    bool arrPossible(vector<int> &nums, int cows, int distance){
        int n = nums.size();
        int cowct = 1;int lastP = 0;
        for(int i = 1; i < n; i++){
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
            
           
        for(int i = 1; i <= rangM; i++){
            if(!arrPossible(nums, k, i)){
                return (i - 1);
            }
        }/*
        return -1;/*Suppose every distance from 1 to rangM is possible
Then loop never enters:
*/
return rangM;
    }
};