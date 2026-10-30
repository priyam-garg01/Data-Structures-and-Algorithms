class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0)return 0;

        int maxLen = 1;
        vector<int> vis(256, 0);
        int i = 0;
        int j = i + 1;
        vis[s[0]] = 1;
        int len;
        while(j < n && i < n){
            if(!vis[s[j]]){
                len = j - i + 1;
                vis[s[j]] = 1;
                maxLen = max(maxLen, len);
                j++;
            }
            else{
                vis[s[i]] = 0;
                // len = j - i + 1;
                //Since this len will always be smaller
                i++;
            }
        }

        return maxLen;
    }
};