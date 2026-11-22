#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        //To find the number of distinct times string t appears in s
        if(n > m)return 0;
        vector<unsigned int> dp(n+1, 0);
        vector<unsigned int> temp(n+1, 0);

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                unsigned int pick = 0;
                if(s[i-1] == t[j-1]){
                    if(j-1 == 0)pick = 1;
                    pick += dp[j-1];
                }
                unsigned int notPick = dp[j];

                temp[j] = pick + notPick;
            }
            dp = temp;
        }

        return dp[n];
    }
};
//Optimal
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        //To find the number of distinct times string t appears in s
        if(n > m)return 0;
        vector<unsigned int> dp(n+1, 0);
        
        for(int i = 1; i <= m; i++){
            for(int j = n; j; j--){
                unsigned int pick = 0;
                if(s[i-1] == t[j-1]){
                    if(j-1 == 0)pick = 1;
                    pick += dp[j-1];
                }
                unsigned int notPick = dp[j];

                dp[j] = pick + notPick;
            }
        }

        return dp[n];
    }
};