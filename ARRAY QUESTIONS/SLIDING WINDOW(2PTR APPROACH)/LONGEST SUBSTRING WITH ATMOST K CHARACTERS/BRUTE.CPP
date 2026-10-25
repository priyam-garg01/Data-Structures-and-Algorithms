/*Given a string s and an integer k.Find the length of the longest substring with at most k distinct characters.


Example 1

Input : s = "aababbcaacc" , k = 2

Output : 6

Explanation : The longest substring with at most two distinct characters is "aababb".

The length of the string 6.

Example 2

Input : s = "abcddefg" , k = 3

Output : 4

Explanation : The longest substring with at most three distinct characters is "bcdd".

The length of the string 4.*/
class Solution {
public:
    int kDistinctChar(string& s, int k) {
        int n = s.size();
        int maxL = 0;
        set<char> st;
        for(int i = 0; i < n; i++){
            int len = 0;
            st.clear();
            for(int j = i; j < n; j++){
                st.insert(s[j]);
                if(st.size() > k){
                    break;
                }
                    len++;
                    maxL = max(maxL, len);
                }
            }
            return maxL;
        }
};//T.C. = O(N^2),S.C. = O(256)//max characters