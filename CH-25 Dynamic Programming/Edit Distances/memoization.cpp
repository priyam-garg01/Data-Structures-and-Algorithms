#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int Distance(int i, int j, string s, string t, vector<vector<int>>& dp){
        if(i < 0)return j + 1;//j+1 insertions to be done
        if(j < 0)return i + 1;//i+1 deletions to be done

        if(s[i] == t[j])return Distance(i-1, j-1, s, t, dp);
        
        int del = 1 + Distance(i-1, j, s, t, dp);
        int insert = 1 + Distance(i, j-1, s, t, dp);
        int replace = 1 + Distance(i-1, j-1, s, t, dp);
        
        return min(del, min(insert, replace));
    }

    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return Distance(n1-1, n2-1, word1, word2, dp);
    }
};/*Memoization: T.C. = O(M*N + M+N), S.C. = O(M*N)*/

class Solution {
public:
    int Distance(int i, int j, string s, string t, vector<vector<int>>& dp){
        if(i == 0)return j;//j insertions to be done
        if(j == 0)return i;//i deletions to be done

        if(s[i-1] == t[j-1])return Distance(i-1, j-1, s, t, dp);
        
        int del = 1 + Distance(i-1, j, s, t, dp);
        int insert = 1 + Distance(i, j-1, s, t, dp);
        int replace = 1 + Distance(i-1, j-1, s, t, dp);
        
        return min(del, min(insert, replace));
    }

    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));

        return Distance(n1, n2, word1, word2, dp);
    }
};