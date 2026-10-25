/*Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.
*/
#include <iostream>
#include <vector>
#include <algorithm> // for sort function

using namespace std;

// M-1 BRUTE FORCE
int majElem(vector<int> nums){
    int n = nums.size();

    for(int value:nums){
        int freq = 0;
        for(int el : nums){
            if(value == el){
                freq++;
            }
        }
        if(freq > n/2){
            cout << value;
            return value;
        }
    }
    return -1;
}


// // M-2 SORTING

// int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());

//         int freq = 1, ans = nums[0];

//         for(int i = 1; i < n; i++){
//             if( nums[i] == nums[i - 1]){
//                 freq++;
//             }
//             else
//                 freq = 1, ans = nums[i];

//         if(freq > n/2){

//             return ans;
//         }

//         }
//         cout << ans;
//         return ans;
//     }
// M-2 Moore's Voting algo

int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int freq = 1, ans = nums[0];

        for(int i = 1; i < n; i++){
            if(freq == 0){
                ans = nums[i];
            }
            if(ans == nums[i]) freq++;
            else freq--;

        }
        // FOR Array with no majorlem,
        int count = 0;
        for(int val: nums){
            if (val == ans)
            count++;
        }
        if (count > n/2){
            return ans;
        }
        else
        return -1;
    }

int main()
{
    vector<int> nums = {1, 2, 2, 2, 2, 1, 1};
    majElem(nums);
    cout << majorityElement(nums);
    return 0;
}