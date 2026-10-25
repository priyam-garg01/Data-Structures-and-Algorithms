#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isPossible(vector<int> arr, int n, int c, int minAllowedDistance){

    sort(arr.begin(), arr.end());//O(nlogn)

    int cows = 1, lastStallPos = arr[0];
    for(int i = 1; i < n; i++){//O(n)
        if(arr[i] - lastStallPos >= minAllowedDistance){
            cows++;
            lastStallPos = arr[i];
        }
        if(cows == c) return true;
    }
    return false;
}

int maxDistance(vector<int> arr, int n, int c){
    // Overall T.C. = O(n*logRange or n*logn) 
    // jo bhi dono mai se bada ho
    int maxValue = INT16_MAX, minValue = INT16_MIN;
    for(int i = 0; i < n; i++){//O(n)
        maxValue = max(maxValue, arr[i]);
        minValue = min(minValue, arr[i]);
    }

    int st = 1, end = maxValue- minValue, ans =-1, mid;
    while(st <= end){//O(log(Range)  * n)
        mid = st + (end-st)/2;
        if(isPossible(arr, n, c, mid)){
            st = mid + 1;
            ans = mid;
        }
        else{
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n = 5, c = 3;
    vector<int> arr = {1, 2, 8, 9, 4};
    cout << maxDistance(arr, n, c);


    return 0;
}