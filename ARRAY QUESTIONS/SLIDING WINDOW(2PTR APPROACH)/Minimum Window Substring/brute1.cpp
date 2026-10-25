class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(n > m)return "";
    int minL = m + 1;
    int stInd = -1;
    for(int i = 0; i < m; i++){
        int hash[256] = {0};    int count = 0;
        for(int k = 0; k < n; k++)hash[t[k]]++;

        for(int j = i; j < m; j++){
            if(hash[s[j]] > 0)count++;
            hash[s[j]]--;
            if(count == n)//all elements of t are there in substring
            {
            if(minL > j - i + 1){
                minL = j - i + 1;
                stInd = i;
                break;
                }
            }

        }
    }
    if(stInd == -1){
        return "";
    }
    string fAns = s.substr(stInd, minL);
       return fAns; 
    }
};/*BRUTE FORCE:
T.C. = O(M^2) + O(N), S.C. = O(1)*/