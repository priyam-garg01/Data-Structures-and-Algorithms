class Solution {
public:
    int kthElement(vector<int> &nums1, vector<int>& nums2, int k) {
   int n1 = nums1.size();
   int n2 = nums2.size();
   int n = n1 + n2;

   int count = 0;

int i = 0; int j = 0;

   while(i < n1 && j < n2){
    
        if(nums1[i] >= nums2[j]){
            count++;
            if(count == k){
                return nums2[j];
            }
            j++;
        }
        else {
            count++;
            if(count == k){
                return nums1[i];
            }
            i++;
        }
   }
   
    while(i < n1){
        count++;
            if(count == k){
                return nums1[i];
            }
            i++;
    }
    while(j < n2){
        count++;
            if(count == k){
                return nums2[j];
            }
            j++;
    }
    return -1;
  }
};