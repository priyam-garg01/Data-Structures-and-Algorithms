class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
// int prefMaxarr[n];
//         int prevMax = height[0];
//         prefMaxarr[0] = prevMax;
//         for(int i = 1; i < n; i++){
//              if(prevMax < height[i]){
//                 prevMax = height[i];
//              }
//              prefMaxarr[i] = prevMax;
//         }

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
int prefMax = INT_MIN;
for(int i = 0; i < n; i++){
    prefMax = max(prefMax, height[i]);
if(height[i] < prefMax && height[i] < suffMaxarr[i]){
    total += min(prefMax, suffMaxarr[i]) - height[i];
    }
}
        
    return total;
    } 
};/*//we can reduce T.C. = O(2N) AND S.C. = O(N) by keeping a prefMax variable in the main loop*/