/*Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.

Note: Please do not copy the description during the contest to maintain the integrity of your submissions.*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        if(n1 == 0)return true;
        if(n2 == 0)return false;
        
        int s1 = 0; int t1 = 0;
        while(t1 < n2 && s1 < n1){
            if(s[s1] == t[t1]){
                s1++;
                t1++;
            }
            else{
                t1++;
            }
            if(s1 == n1)return true;
        }
        return false;
    }//T.C. = O(N2), S.C. = O(N1 + N2)
};