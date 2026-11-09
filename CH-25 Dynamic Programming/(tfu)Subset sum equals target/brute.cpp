#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    bool isTarget(int idx, vector<int>& arr, int target){
        if(target == 0)return true;
        if(idx < 0)return false;
        if(arr[idx] > target){
            return isTarget(idx-1, arr, target);
        }
        //Take
        int pick = isTarget(idx-1, arr, target-arr[idx]);
        if(pick)return true;

        //Dont Take
        int notPick = isTarget(idx-1, arr, target);
        return notPick;

    }
    
    bool isSubsetSum(vector<int>arr, int target){
        int n = arr.size();
   
        if(isTarget(n-1, arr, target))return 1;
        return 0;
    }
};//T.C. = O(2^N), S.C. = O(N)