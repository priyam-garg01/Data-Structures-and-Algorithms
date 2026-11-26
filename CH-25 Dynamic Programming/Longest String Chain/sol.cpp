/*You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

 

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
Example 3:

Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
 

Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of lowercase English letters.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//Wrong approach: we need to check if they are differentiating by one char
    // bool isPresent(string s1, string s2){
    //     int i = 0;
    //     int j = 0;
    //     while(i < s1.size() && j < s2.size()){
    //         if(s1[i] == s2[j]){
    //             i++; j++;
    //         }
    //         else j++;
    //     }
    //     if(i == s1.size())return true;
    //     return false;
    // }
    bool isPresent(string s1, string s2){
        if(s1.size() != s2.size()-1)return false;
        int i = 0;
        int j = 0;
        while(i < s1.size() && j < s2.size()){
            if(s1[i] == s2[j]){
                i++; j++;
            }
            else{
                j++;
            }
        }
        // if(diff == 1)return true;
        //Wrong Comparison
        //If the insertion is done at last and ith ptr is already done diff == 0 return false
        if(i == s1.size() && (j == s2.size() || j == s2.size()-1))return true;
        return false;
    }
    static bool comp(string& s1, string& s2){
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);

        int maxi = 1; 
        int lastIdx = 0;
        //The order is should be increasing
        sort(words.begin(), words.end(), comp);//We sort in terms of len of words
    /*If comp is a non-static member function of a class, passing it directly into std::sort will fail to compile. It must be marked static (or defined as a lambda/free function)*/
    
        for(int i = 1; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(isPresent(words[prev], words[i]) && dp[prev] + 1 > dp[i]){
                    dp[i] = dp[prev] + 1;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIdx = i;
            }
        }
        return maxi;
    }
};/*T.C. = O(N*N*L + NLOGN), S.C. = O(N){L = avg len of string} given lmax = 16*/