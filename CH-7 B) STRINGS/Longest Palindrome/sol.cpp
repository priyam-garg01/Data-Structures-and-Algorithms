/*Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

 

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
 

Constraints:

1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.
*/
class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        //A palindrome consists letters or char in even freq
        vector<int> freq(52, 0);

        for(int i = 0; i < n; i++){
            if(s[i] <= 90){
                freq[s[i] - 'A']++;
            }
            else{
                freq[26 + s[i] - 'a']++;
            }
        }
        int len = 0;
        int odd = 0;;
        // int i = 0;
        // int evens = 0;
        // while(i < 52){
        //     if(!freq[i]){
        //         i++;
        //         continue;
        //     }
        //     evens = freq[i]/2;
        //     if(freq[i] % 2 == 1)odd = 1;
        //     len += evens*2;
        //     i++;
        // }

        for(int i = 0; i < 52; i++){
            if(freq[i] % 2 == 0){
                len += freq[i]
            }
            else{
                len += freq[i] - 1;
                odd = 1;
            }
        }

    len += odd;
    
    return len;
    }
};//T.C. = O(N), S.C. = O(52) = O(1)