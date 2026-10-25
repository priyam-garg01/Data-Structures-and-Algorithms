class Solution {
public:
/*1.Sort the array
2. Find duplicate number by arr[i-1]=arr[i]
3. Find missing numbe rby implementing 2 loops

 */ vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n = nums.size();
        int dualElem;
        int missingElem;
        vector<int> vec;

        //For repeating
        for(int i = 1; i < n; i++){
            if(nums[i-1] == nums[i]){
                dualElem = nums[i];
            }
        }

        //For missing number
        for(int i = 1; i <= n; i++){
            int flag = 1;
            for(int j = 0; j < n; j++){
                if(nums[j] == i){
                    flag = 0;
                } 
            }
            if(flag == 1){
            missingElem = i;
            break;
            }
        }
        vec.push_back(dualElem);
        vec.push_back(missingElem);
        return vec;
    }
};