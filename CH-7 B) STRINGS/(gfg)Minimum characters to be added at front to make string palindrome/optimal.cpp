/*Given a string s, the task is to find the minimum characters to be added at the front to make the string palindrome.

Examples:

Input: s = "abc"
Output: 2
Explanation: Add 'b' and 'c' at front of the above string to make it palindrome: "cbabc"
Input: s = "aacecaaaa"
Output: 2
Explanation: Add 2 a's at front of the above string to make it palindrome: "aaaacecaaaa"
Constraints:

1 ≤ s.size() ≤ 106
s consists only of lowercase English alphabets*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minChar(string &s) {
        int n = s.size();
        
        /*USING LPS:
        1)Reverse the string 
        2)Add a special symbol in the copied string and concatenate the reverse to 
        distinguish between the reverse and og so that the palindrome len doesn't come wrong and
        exceed the string length
        3)LPS helps us to find the longest palindrome that we can get from the string
        3)Apply LPS on the string made and the last element will be subtracted from the 
        string len
        */
        
        string rev;
        for(int i = n - 1; i >= 0; i--){
            rev += s[i];
        }
        
        string s1 = s;
        s1 += '&';
        s1 += rev;
        
        vector<int> LPS(2*n + 1, 0);
        int pre = 0; 
        int suf = 1;
        while(suf < 2*n + 1){
            if(s1[pre] == s1[suf]){
                LPS[suf] = pre + 1;
                pre++;
                suf++;
            }
            else{
                if(pre != 0){
                    pre = LPS[pre - 1];
                }
                else{
                    suf++;
                }
            }
        }
        return n - LPS[2*n];
    }
};/*T.C. = O(N) + O(2*N + 1) == O(N), S.C. = O(2(2*N + 1) + N) = O(N)*/
/*Note: If asked about which chars are these last n - LPS[2*n] chars of OG string */
