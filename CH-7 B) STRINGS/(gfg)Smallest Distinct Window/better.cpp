class Solution {
  public:
    int findSubString(string& s) {
        int n = s.size();
        if(n == 1)return 1;
        
        unordered_set<char> distinct;
        
        for(int i = 0; i < n; i++){
            distinct.insert(s[i]);
        }
        
        int len = n;
        
        int size = distinct.size();
        
        unordered_map<char, int> freq;
        int i = 0; 
        int j = 0;
        int count = 0;
        
        while(j < n){
            while(count < size && j < n){
                if(freq[s[j]] == 0)count++;
                freq[s[j]]++;
                j++;
            }
           
            while(count == size){
                len = min(len, j - i);
                freq[s[i]]--;
                if(freq[s[i]] == 0)count--;
                i++;
            }
            
        }
        
        return len;
    }
};