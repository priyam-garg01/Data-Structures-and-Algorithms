

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++){
            int elem = nums1[i];
            for(int j = 0; j < nums2.size(); j++){
                if(nums2[j] == elem){ 
                    j++;
                    while(j < nums2.size()){
                        if(nums2[j] > elem){
                            ans.push_back(nums2[j]);
                            break;
                        }
                        j++;
                    }
                if(ans.size() != i + 1){
                    ans.push_back(-1);
                    break;/*Suppose nums2 = [1,3,4,2] and elem = 1.

You find 1.
You find 3, so you push 3.
But the outer for(j...) continues after the while ends.
Then ans.size() == i+1, so nothing else is pushed in this case.*/
                    }
                }
            }
        }
        return ans;
    }
};
/*T.C. = O(M*N), S.C. = O(1)*/