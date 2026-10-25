class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
    int total = 0;
    int lMax = 0;
    int rMax = 0;
    int l = 0;
    int r = n-1;
    while(l < r){
        if(height[l] <= height[r]){
            if(height[l] < lMax){
                total += lMax - height[l];
            }
            else lMax = height[l];
            l++;
        }
        else{//if right element is smaller
            if(height[r] < rMax){
                total += rMax - height[r];
            }
            else rMax = height[r];
            r--;
        }
    }
        
    return total;
    } 
};/*
//Two pointer approach:
We will operate on the height which is smaller, As we only need the smaller part of both sides to find the water stored on that roof: Iterating from both sides checking which has the smaller height and side by side updating the leftMax and right max
T.C. = O(N), S.C. = O(1)
*/