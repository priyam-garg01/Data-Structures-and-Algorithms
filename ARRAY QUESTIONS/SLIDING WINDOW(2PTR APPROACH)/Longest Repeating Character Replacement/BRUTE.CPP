/*You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
 

Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxL = 0;
        for(int i = 0; i < n; i++){
        vector<int> hash(26,0);//notes the freq of characters
        int maxF = 0;//to note the max freq of the element
            int changes = 0;
            for(int j = i; j < n; j++){
                hash[s[j] - 'A']++;
                maxF = max(maxF, hash[s[j] - 'A']);
            int changes = j - i + 1 - maxF;
            if(changes <= k){
                maxL = max(maxL, j-i+1);
                }
            else {
                break;
            }
            }
        }
        return maxL;
    }
};/*BRUTE FORCE :
Take a vector of size 26 and store the characters freq in it , keep a variable maxF to note the
 element with greatest occurrences in the substring and a variable changes to determine the different 
 elements other than the maxF element by subtracting maxF from total len of substring
T.C. = O(N^2), S.C. = O(26)*/