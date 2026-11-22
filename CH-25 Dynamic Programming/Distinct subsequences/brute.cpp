/*Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

 

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag
 

Constraints:

1 <= s.length, t.length <= 1000
s and t consist of English letters.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int numMatches(int i, int j, string s, string t){
        if(i < 0 || j < 0)return 0;
        // if(j == 0){//if string is matched early it lefts behind all other which could have been added
        //     if(i >= 0 && s[i] == t[j])return 1;
        //     return numMatches(i-1, j, s, t);
        // }
        int pick = 0;
        if(s[i] == t[j]){
            if(j == 0)pick = 1;
            pick += numMatches(i-1, j-1, s, t);
        }
        int notPick = numMatches(i-1, j, s, t);

        return pick + notPick;
    }

    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        //To find the number of distinct times string t appears in s
        if(n > m)return 0;
        return numMatches(m-1, n-1, s, t);
        
    }
};