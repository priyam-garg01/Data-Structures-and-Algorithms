/*Given a string s, your task is to find the length of the smallest window that contains all the characters of the given string at least once.

Example:

Input: s = "aabcbcdbca"
Output: 4
Explanation: Sub-String "dbca" has the smallest length that contains all the characters of string s.
Input: s = "aaab"
Output: 2
Explanation: Sub-String "ab" has the smallest length that contains all the characters of string s.
Input: s = "geeksforgeeks"
Output: 7
Explanation: There are multiple substring with smallest length that contains all characters of string s, "eksforg" and "ksforge". 
Constraints:

1 ≤ s.size() ≤ 105
s consists only of lowercase English alphabets*/
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
        
        //A window of size mpp.size() is created iterating till the end
        int size = distinct.size();
        for(int i = 0; i < n; i++){
            unordered_map<char, int> freq;
            int count = 0;
            for(int j = i; j < n; j++){
                if(freq[s[j]] == 0)count++;
                freq[s[j]]++;
            if(count == size){
                len = min(len, j - i + 1);
                break;
            }
            }
        }
        
       
        
        return len;
    }
};//T.C. = O(N), S.C. = O(2N);