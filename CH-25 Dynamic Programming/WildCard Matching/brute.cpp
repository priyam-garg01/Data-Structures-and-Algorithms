/*Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 

Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkMatch(int i, int j, string s, string t){
        if(i < 0 && j < 0)return true;
        if(i < 0 && j >= 0){
            // if(j == 0 && t[j] == '*')return true;
            // return false;It may have all stars
            for(int k = j; k >= 0; k--){
                if(t[k] != '*')return false;
            }
            return true;
        }
        if(i >= 0 && j < 0)return false;


        if(t[j] == '?' || s[i] == t[j])return checkMatch(i-1, j-1, s, t);
        if(t[j] == '*')return checkMatch(i-1, j, s, t)|| checkMatch(i, j-1, s, t);//delete char and keep star OR delete star for nothing
        return false;//if none of the above cases are there
    }

    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();

        return checkMatch(n1-1, n2-1, s, p);
    }
};/*Brute Force: T.C. = O(2^(M+N)), S.C. = O(M + N)*/