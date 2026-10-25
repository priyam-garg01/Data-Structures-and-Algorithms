/*Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.
Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9*/

class Solution {
public:


    int prefixMax(int index,vector<int>& height){
        int n = height.size();
        int prefMaxarr[n];
        int prevMax = height[0];
        prefMaxarr[0] = prevMax;
        for(int i = 1; i < n; i++){
             if(prevMax < height[i]){
                prevMax = height[i];
             }
             prefMaxarr[i] = prevMax;
        }
        return prefMaxarr[index];
    }
    int suffixMax(int index,vector<int>& height){
        int n = height.size();
        int suffMaxarr[n];
        int suffMax = height[n-1];
        suffMaxarr[n-1] = suffMax;
        for(int i = n-2; i >= 0; i--){
            if(height[i] > suffMax){
                suffMax = height[i];
            }
            suffMaxarr[i] = suffMax;
        }
        return suffMaxarr[index];
    }


    int trap(vector<int>& height) {
        int n = height.size();


int prefMaxarr[n];
        int prevMax = height[0];
        prefMaxarr[0] = prevMax;
        for(int i = 1; i < n; i++){
             if(prevMax < height[i]){
                prevMax = height[i];
             }
             prefMaxarr[i] = prevMax;
        }

int suffMaxarr[n];
        int suffMax = height[n-1];
        suffMaxarr[n-1] = suffMax;
        for(int i = n-1; i >= 0; i--){
            if(height[i] > suffMax){
                suffMax = height[i];
            }
            suffMaxarr[i] = suffMax;
        }

    int total = 0;

for(int i = 0; i < n; i++){
if(height[i] < prefMaxarr[i] && height[i] < suffMaxarr[i]){
    total += min(prefMaxarr[i], suffMaxarr[i]) - height[i];
    }
}
        
    return total;
    } 
};/*//For trapping rainwater there is a condition that if the element in the array is smaller than its prev and next element then only it can store water and the prev and next elements can be next to prev and next to next i.e. k+1, k+2th elements or k-1, k-2th elements
// The formula to calc the water trapped is min(prevMax, nextMax) - arr[i];
T.C. = O(N) + O(N) + O(N) == O(3N),, S.C. = O(2N)*/