#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(vector<int> arr, int n, int m, int maxTimeAllowed){
     int ptr = 1, time = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > maxTimeAllowed){
            return false;
        }
       
        if(time + arr[i] <= maxTimeAllowed){
            time += arr[i];
        }
        else{
            ptr++;
            time = arr[i];
    }
    }
    return ptr > m ? false : true;
}

int painterAllocTime(vector<int> arr, int n, int m){
    int sum = 0, maxVal = arr[0];
    for(int i = 0; i < n; i++){
        sum += arr[i];
        maxVal = max(maxVal, arr[i]);
    }

    int st = maxVal, end = sum, mid, ans = -1;
    while(st <= end){
        mid = st + (end-st)/2;
        if(isValid(arr, n, m, mid)){
            ans = mid;
            end = mid-1;
        }
        else
            st = mid +1;
    }
    return ans;
}
int main()
{
    vector<int> arr {5, 7, 2, 1};
    int n = 4, m= 3;
    cout << painterAllocTime(arr, n, m);
    return 0;
}