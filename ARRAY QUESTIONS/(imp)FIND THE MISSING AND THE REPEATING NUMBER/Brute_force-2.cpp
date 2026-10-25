/*   1.Run two loops first for numbers 1 to n
second to check the array elements
2.inintiate count to zero 
3.IF COUNT REMAINS ZERO MISSING ELESE COUNT = 2 DUAL ELEMENT
*/

class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n = nums.size();
        int dualElem = -1
        int missingElem = -1
        vector<int> vec;

        for(int i = 1; i <= n; i++){
            int count = 0;
            for(int j = 0; j < n; j++){
                    if(nums[j] == i){
                        count++;
                    }
            }
            if(count == 0){
                missingElem = i;
            }
            if(count == 2){
                dualElem = i;
            }
            if(missingElem!= -1 && dualElem != -1){
                break;
            }
        }
        vec.push_back(dualElem);
        vec.push_back(missingElem);
        return vec;
    }
};