class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        //here fruits[i] doesnt represent the number of fruits but the type of fruits like type 1, type 0, ....
        //This problem can be simplified into finding the longest subarray with atmost 2 different integers
        int maxCt = 0;
            unordered_map<int, int>mpp;

        int l = 0; int r = 0;
        while(r < n){
            mpp[fruits[r]] = r;
        if(mpp.size() > 2){
            if(l == mpp[fruits[l]]){
                mpp.erase(fruits[l]);
                }
                l++;
        }
        if(mpp.size() <= 2){
            maxCt = max(maxCt, r-l+1);
            r++;   
            }
        }
        return maxCt;
    }
};/*We can note the last occurrence of that type of fruit and move l to that index and side by side moving r to maintain the maxCt
T.C. = O(2N), S.C. = O(3)
Also a map of type, freq can be taken with condition if freq of any type = zero erase that element*/