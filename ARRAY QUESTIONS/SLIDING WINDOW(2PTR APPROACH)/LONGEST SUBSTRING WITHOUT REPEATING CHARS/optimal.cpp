class Solution {
public:



    // bool duplicate(string s){
    //     int n = s.size();
    //     unordered_map<char, int> mpp;
    //     for(int i = 0; i < n; i++){
    //         if(mpp[s[i]] == 1){
    //             return true;
    //         }
    //         mpp[s[i]]++;
    //     }
    //     return false;
    // }
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0)return 0;
        int maxL = 0;
        unordered_map<char, int> mpp;
        //this will store the character and the index at which it lies in the string
 //we can also use an int has[256] = {-1};
        int l = 0; int r = 0;
        int len = 0;
        while(r < n && l < n){
            // if(mpp.find(s[r]) == mpp.end())
            //wrong as the lement index is still stored in hashmap althpugh left pointer has surpassed those characters
            if(mpp.find(s[r]) == mpp.end() || mpp[s[r]] < l)//condition of not found under the sliding window
            {
                mpp[s[r]] = r;
                len = r - l + 1;
                r++;
            }
            else{//if repeated element is present
            //IMP LOGIC IF REPEATED ELEMENT IS ENCOUNTERED
                l = mpp[s[r]] + 1;//left shifts to index 1 greater than the repeated index
                mpp[s[r]] = r;
                len = r - l + 1;
                r++;
            }
                maxL = max(maxL, len);
        }
        return maxL;
    }
};/*OPTIMAL:
T.C. = O(N){as r is moved every single time}, S.C. = O(N){can be O(256)}*/