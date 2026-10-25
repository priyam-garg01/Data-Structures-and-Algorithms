class Solution {
  public:
    string sortString(string &arr) {
        int n = arr.size();
        //Brute: O(NLOGN)

        //Better: T.C. = O(N), S.C. = O(N)
        vector<int> freq(26, 0);
        
        for(int i = 0; i < n; i++){
            freq[arr[i] - 'a']++;
        }
        
        string ans;
        int i = 0;
        while(i < 26){
            while(freq[i]){
                char c = 'a' + i;
                ans.push_back(c);
                freq[i]--;
            }
            i++;
        }
        
        return ans;

        //Optimal: T.C. = O(N), S.C. = O(1);        
        vector<int> freq(26, 0);
        
        for(int i = 0; i < n; i++){
            freq[arr[i] - 'a']++;
        }
        int i = 0; int j = 0;
        while(i < 26){
            while(freq[i]){
                char c = 'a' + i;
                arr[j++] = c;  
                freq[i]--;
            }
            i++;
        }
        return arr;
    }
};