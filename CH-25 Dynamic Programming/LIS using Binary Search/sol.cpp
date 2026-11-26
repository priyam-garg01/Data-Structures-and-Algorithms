#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);

        for(int i = 1; i < n; i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int ind = lower_bound(temp.begin(), temp.end(), nums[i])-temp.begin();//returns an iterator so subtract it from begining iterator of temp(temp.begin())
                temp[ind] = nums[i];
            }
        }
        int len = temp.size();
        return len;
    }
};/*Binary Search: Concept of lower bound used to the replace the larger elements
Temp doesn't return the LIS but gets us the len
T.C. = O(N*LOGN), S.C. = O(N)*/