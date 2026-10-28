class Solution {
  public:
    int getLPSLength(string &s) {
        int n = s.size();
        
        int pref = 0;
        int suff = pref + 1;
        int len = 0;
        vector<int> LPS(n, 0);
        
        
        while(suff < n){
            if(s[pref] == s[suff]){
                LPS[suff] = pref + 1;
                pref++;
                suff++;
            }
            
            else{
                if(pref == 0){
                    LPS[suff] = 0;
                    suff++;
                }
                else{
                    pref = LPS[pref - 1];//Pref decreases by huge levels so the step count is measurable that's ehy not included in T.C.
                }
            }
        }
        
    return LPS[n - 1];
    }
};//T.C. = O(N), S.C. = O(N)