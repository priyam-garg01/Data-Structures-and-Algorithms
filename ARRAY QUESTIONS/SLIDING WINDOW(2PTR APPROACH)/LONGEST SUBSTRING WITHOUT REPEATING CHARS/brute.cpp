/*Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.*/
class Solution {
public:



    bool duplicate(string s){
        int n = s.size();
        unordered_map<char, int> mpp;
        for(int i = 0; i < n; i++){
            if(mpp[s[i]] == 1){
                return true;
            }
            mpp[s[i]]++;
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0)return 0;
    // BRUTE FORCE: FIND ALL SUBSTRINGS
    int maxL = 1;
    for(int i =0; i < n; i++){
        string ans;
        int len = 0;
        for(int j = i; j < n; j++){
                ans.push_back(s[j]);
                if(duplicate(ans)){
                    len = 0;
                    break;
                }
                len++;
                maxL = max(len, maxL);
            }
        }
        return maxL;
    }
// };T.C. = O(N^3), S.C. = O(N)