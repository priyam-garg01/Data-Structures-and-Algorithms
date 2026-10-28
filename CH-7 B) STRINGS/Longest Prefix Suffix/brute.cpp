/*Given a string s, of lowercase english alphabets, find the length of the longest proper prefix which is also a suffix.
Note: Prefix and suffix can be overlapping but they should not be equal to the entire string.

Examples :

Input: s = "abab"
Output: 2
Explanation: The string "ab" is the longest prefix and suffix. 
Input: s = "aabcdaabc"
Output: 4
Explanation: The string "aabc" is the longest prefix and suffix.
Input: s = "aaaa"
Output: 3
Explanation: "aaa" is the longest prefix and suffix. 
Constraints:

1 ≤ s.size() ≤ 106
s consists only of lowercase English alphabets*/
class Solution {
  public:
    int getLPSLength(string &s) {
        int n = s.size();
        
        //Brute:Check all strings uptill end - 1{Prefix and suffix can be overlapping but they should not be equal to the entire string.}
        
        int size; 
        int sIdx = n - 1;
        int len = 0;
        int maxL = 0;
        
        for(int i = 0; i < n; i++){//O(N)
            string curr;
            for(int j = 0; j <= i; j++){//O(N)
                curr += s[j];
            }
            sIdx = n - 1;
            len = 0;
            if(curr.size() == n)break;
            size = curr.size();
            
            string match;
            int k = 0;
            while(k != size){//O(N)
                match += s[n - 1 - k];
                k++;
            }
            reverse(match.begin(), match.end());//O(N)
            if(match == curr)maxL = max(maxL, size);
            
    }
    
    return maxL;
    }//T.C. = O(N^3), S.C. = O(2N);
};