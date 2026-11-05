#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();
        //We need the last two ptr values
        int prev = 0;
        int nextPrev = 0;
        int curr;

        for(int idx = 0; idx < n; idx++){
            int P = nums[idx] + nextPrev;
            int nP = prev;

            curr = max(P, nP);
            nextPrev = prev;
            prev = curr;
        }
        
        return prev;
    }
};//T.C. = O(N), S.C. = O(1)