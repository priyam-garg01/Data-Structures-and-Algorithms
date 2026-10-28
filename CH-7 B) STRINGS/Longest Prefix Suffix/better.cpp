class Solution {
  public:
    int getLPSLength(string &s) {
        int n = s.size();
        
        int maxL = 0;
        
        for(int len = 1; len < n; len++){
            bool match = true;
            for(int k = 0; k < len; k++){
                if(s[k] != s[n - len + k]){
                    match = false;
                    break;
                }
            }
            if(match)maxL = len;
        }
    
    return maxL;
    }
};//T.C. = O(N^2), S.C. = O(1)