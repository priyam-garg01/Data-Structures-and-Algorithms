class Solution {
public:
    void Lps(string s, int n, vector<int> &LPS){
        int pre = 0, suf = 1;

        while(suf < n){
            if(s[suf] == s[pre]){
                LPS[suf] = pre + 1;
                suf++; pre++;
            }
            else{
                if(pre != 0){
                    pre = LPS[pre - 1];
                }
                else{
                    LPS[suf] = 0;
                    suf++;
                }
            }
        }
        return;
    }

    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int s = needle.size();
        int first = 0, second = 0;
        vector<int> LPS(s, 0);

        Lps(needle, s, LPS);
        
        while(first < n && second < s){
            if(haystack[first] == needle[second]){
                first++;
                second++; 
                if(second == s){
                    return first - second;
                }
            }
            else{
                if(second != 0){
                    second = LPS[second - 1];
                } 
                else first++;
            }
        }
        return -1;
    }//T.C. = O(N + M), S.C. = O(M) 
};