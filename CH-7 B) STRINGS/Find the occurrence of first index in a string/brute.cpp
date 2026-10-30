/*Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.*/

/*Brute force: checking each substring on comparing their chracters*/
lass Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int s = needle.size();
        int first = 0, second = 0;
        int minIdx = n;
        int lastMatch = -1;
        while(first < n){
            if(haystack[first] == needle[second]){
                if(second == 0)lastMatch = first;
                first++;
                second++;
                if(second == s){
                    minIdx = min(minIdx, first - s);
                    return minIdx;
                }
            }
            else{
                if(lastMatch != -1){
                    first = lastMatch + 1;
                    lastMatch = -1;
                }
                else first++;
                second = 0;
            }
        }
        if(minIdx == n)return -1;

        return minIdx;
    }
};