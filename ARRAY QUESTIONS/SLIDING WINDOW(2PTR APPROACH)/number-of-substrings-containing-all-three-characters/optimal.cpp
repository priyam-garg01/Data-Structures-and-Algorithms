class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char, int> mpp;
            int ct = 0;
        int r = 0; 
        int l = 0;
        while(r < n){
            mpp[s[r]]++;

            while(mpp['a'] && mpp['b'] && mpp['c']){
                ct += n-r;
                mpp[s[l]]--;
                l++;
            }
            if(!(mpp['a'] && mpp['b'] && mpp['c'])){//we will only move r when the window doesnt have a or b or c
                r++; 
            }
        }
            return ct;
    }
};/*optimal: Forward Marching
//we will only move r when the window doesnt have a or b or c
map stores the char and its freq
T.C. = O(2N), S.C. = O(3) here we can't reduce to O(n) as we are finding the number of substrings and not the length of substring
*/