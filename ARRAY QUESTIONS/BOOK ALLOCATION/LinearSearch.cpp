//Similar to Aggressive cows



class Solution {
public:
    bool isPossible(vector<int> &nums, int students, int pages){
        int n = nums.size();
        int stdCt = 1; int sumPage = 0;
        for(int i = 0; i < n; i++){
                    sumPage += nums[i]; 
                if(sumPage > pages){
                    sumPage = nums[i];
                    stdCt++;
                }
            }
            if(stdCt <= students){//<= and not only = for in binary searching
                return true;
            }   
            else return false; 
        }
    int findPages(vector<int> &nums, int m)  {
         int n = nums.size();
         if(m > n){
            return -1;
         }
         /*NO SORTING AS BOOK ALLOCATION HAS TO BE CONTIGUOUS
         //Firstly we need to sort the array so that pages(of a single book) allocated to the student at last is max
         sort(nums.begin(), nums.end());
         */
         //Range will be from the maximum element in array to the summation of array elements(if m = 1);
        int sum = 0; 
        int maxi = 0;
         for(int i = 0; i < n; i++){
                sum += nums[i];
                maxi = max(maxi, nums[i]);
         }

         for(int i = maxi; i <= sum; i++){
            if(isPossible(nums, m, i)){
                return i;
            }
         }
         return -1;
    }
};