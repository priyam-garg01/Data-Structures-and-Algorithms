class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(n > m)return "";
   

    int hash[256] = {0};
    for(int i = 0; i < n; i++){
        hash[t[i]]++;
    }

    string ans;
    int minL = m + 1;
    //"infinity" sentinel, since m itself is a valid length
    int stInd = -1;
    int count = 0;


    int i = 0; 
    int j = 0;
    
    while(j < m){
        if(hash[s[j]] > 0)count++;
        hash[s[j]]--;

        while(count == n){
            if(minL > j - i + 1){
                minL = j - i + 1;
                stInd = i;
            }
            hash[s[i]]++;//this will come first means before checking hash[s[i]] > 0
            if(hash[s[i]] > 0)count--;
            i++;
        }
        if(count < n){
        j++;
        }
    }
    if(stInd == -1)return "";


    ans = s.substr(stInd, minL);
    return ans;
        
    }
};/*OPTIMAL:
T.C. = O(N) +O(2M), S.C. = O(256)*/