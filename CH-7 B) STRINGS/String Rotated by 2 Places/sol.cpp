/*Given two strings s1 and s2. Return true if the string s2 can be obtained by rotating (in any direction) string s1 by exactly 2 places, otherwise, false.

Note: Both rotations should be performed in same direction chosen initially.

Examples:

Input: s1 = "amazon", s2 = "azonam"
Output: true
Explanation: "amazon" can be rotated anti-clockwise by two places, which will make it as "azonam".
Input: s1 = "geeksforgeeks", s2 = "geeksgeeksfor"
Output: false
Explanation: If we rotate "geeksforgeeks" by two place in any direction, we won't get "geeksgeeksfor".
Input: s1 = "ab", s2 = "ab"
Output: true
Explanation: If we rotate "ab" by two place in any direction, we always get "ab".
Constraints:

1 ≤ s1.size(), s2.size() ≤ 105*/
class Solution {
  public:
    void rotateClockwise(string& s){//O(N)
        int size = s.size();
        if(s.size() <= 1)return;
        
        int i = size - 2;
        while(i >= 0){
            swap(s[i + 1], s[i]);
            i--;
        }
    }
    
    void rotateAnti(string& s){//O(N)
        int size = s.size();
        if(s.size() <= 1)return;
        
        int i = 1;
        while(i < size){
            swap(s[i - 1], s[i]); 
            i++;
        }
    }
    bool isRotated(string& s1, string& s2) {
        int n = s1.size();
        int k = 2;
        // if(n == k)return true;//If char in string are diff
        if(s1.size() != s2.size())return false;
        
        string ans = s1;
        
        while(k){
            rotateClockwise(ans);
            k--;
        }
        if(ans == s2)return true;
        
        ans = s1;
        
        k = 2;
        
        while(k){
            rotateAnti(ans);
            k--;
        }
        if(ans == s2)return true;
        
        return false;
    }//T.C. = O(4N) = O(N), S.C. = O(2N1 + N2)
};
