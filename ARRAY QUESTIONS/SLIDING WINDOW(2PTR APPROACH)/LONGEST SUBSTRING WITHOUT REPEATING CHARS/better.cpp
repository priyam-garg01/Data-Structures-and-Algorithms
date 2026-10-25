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
    // BRUTE FORCE: FIND ALL SUBSTRINGS
    int maxL = 1;
    for(int i =0; i < n; i++){
        int hash[256] = {0};//hash array representing the occurences of 255 characters
        for(int j = i; j < n; j++){
                if(hash[s[j]] == 1)break;
                int  len = j-i+1;
                maxL = max(len, maxL);
                hash[s[j]] = 1;
            }
        }
        return maxL;
    }
};/*BETTER:
T.C. = O(N), S.C. = O(256*2(UNITS))*/