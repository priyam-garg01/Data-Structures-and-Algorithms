#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
  
    int countWays(int n) {
        vector<int> dp(n + 1, -1);
        int prevStep = 1;
        int nextPrevStep = 1;
        
        int idx = 2;
        int Step = 1;
        while(idx <= n){
            Step = prevStep + nextPrevStep;
            nextPrevStep = prevStep;
            prevStep = Step;
            idx++;
        }
        
        return Step;
    }//T.C. = 0(N)
};