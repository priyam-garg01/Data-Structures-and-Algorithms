/*Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.*/
class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(n > m)return "";
    unordered_map <char, int> mpp;

    for(int i = 0; i < n; i++){
        mpp[t[i]]++;
    }

    int size = m + 1;//"infinity" sentinel, since m itself is a valid length
    string fAns;

    for(int i = 0; i < m; i++){
        string ans;
        unordered_map<char, int> mp = mpp;

        for(int j = i; j < m; j++){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                ans = s.substr(i, j - i + 1);
            }
            if(mp[s[j]] == 0){
                mp.erase(s[j]);
            }
            if(mp.empty()){
                if((int)ans.size() < size){
                size = ans.size();//ans.size() return a string not int
                fAns = ans;
                }
                break;
            }
        }
    }
        return fAns;
    }
};/*BRUTE FORCE:
T.C. = O(N) + O(M^2), S.C. =O(2N) == O(2*256)= O(1)*/