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
class Solution {
  public:
    bool isPalindrome(string s, int st, int end){
        while(st <= end){
            if(s[st] != s[end])return false;
            st++;
            end--;
        }
        return true;
    }
    int minChar(string &s) {
        int n = s.size();
        
        int st = 0; int end = n - 1;
        int count = 0;
        
        while(st <= end){
            if(isPalindrome(s, st, end)){
                st++;
                end--;
            }
            else{
                count++;
                end--;
            }
        }
        
        return count;
    }//T.C. = O(N*N), S.C. = O(1)
};