/*1.Use hashing to store the count
*/

class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n = nums.size();
        int dualElem = -1;
        int missingElem = -1;
        vector<int> vec;
        
        //To store count we can use hashmap
       // T.C. = O(3N, S.C. = O(N);
        map<int, int> mpp;
        for(int i = 1 ; i <= n; i++){
            mpp[i] = 0;
        }
            for(int i = 0 ; i < n; i++){
                    mpp[nums[i]]++;
                }
                for(auto it : mpp){
                    if(it.second == 0){
                        missingElem = it.first;
                    }
                    if(it.second == 2){
                        dualElem = it.first;
                    }
                    if(dualElem != -1 && missingElem != -1){
                        break;
                    }
                }
        //To store count we can use hasharr
// T.C. = O(2N), S.C. = O(N+1);
        int hash[n+ 1] = {0};
        for(int i = 0; i < n; i++){
            hash[nums[i]]++;
        }

        for(int i=1 ;i< n;i++){
            int count = 0;
            if(hash[i] == 0){
                missingElem = i;
            }
            if(hash[i] == 2){
                dualElem = i;
            }
            if(dualElem != -1 && missingElem != -1){
                        break;
                    }
                }



        vec.push_back(dualElem);
        vec.push_back(missingElem);
        return vec;
    }
};