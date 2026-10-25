class Solution {
public:
    int kthElement(vector<int> &nums1, vector<int>& nums2, int k) {
   int n1 = nums1.size();
   int n2 = nums2.size();
   int n = n1 + n2;

   vector<int> ans;

int i = 0; int j = 0;

   while(i < n1 && j < n2){
    
        if(nums1[i] >= nums2[j]){
            ans.push_back(nums2[j++]);
        }
        else ans.push_back(nums1[i++]);
   }
   
    while(i < n1){
        ans.push_back(nums1[i++]);
    }
    while(j < n2){
        ans.push_back(nums2[j++]);
    }
    return ans[k-1];
  }
};