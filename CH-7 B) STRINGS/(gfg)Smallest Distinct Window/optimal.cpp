class Solution {
  public:
    int findSubString(string& s) {
        int n = s.size();
        if(n == 1)return 1;
        
        int diff = 0;
        vector<int> count(256, 0);
        
        for(int i = 0; i < n; i++){
            if(count[s[i]]++ == 0)diff++;
        }
        count.assign(256, 0);
        
        int len = n;
        
        int i = 0; 
        int j = 0;
        
        while(j < n){
            while(diff && j < n){
                if(count[s[j]] == 0)diff--;
                count[s[j]]++;
                j++;
            }
           
            len = min(len, j - i);
            while(diff != 1){
                len = min(len, j - i);
                count[s[i]]--;
                if(count[s[i]] == 0)diff++;
                i++;
            }
            
        }
        
        return len;
    }
};