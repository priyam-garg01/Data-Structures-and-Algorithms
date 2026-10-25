class Solution {
public:
    int kDistinctChar(string& s, int k) {
        int n = s.size();
        int maxL = 0;
        int l = 0; 
        int r = 0;
        unordered_map<char, int> mpp;
        while(r < n){
            mpp[s[r]]++;
            while(mpp.size() > k){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0){
                    mpp.erase(s[l]);
                }
                l++;
            }
            if(mpp.size() <= k){
            maxL = max(maxL, r - l + 1);
            }
        r++;
        }
            return maxL;
        }
};//T.C. = O(2N) + O(LOGN256), S.C. = O(256)//max characters