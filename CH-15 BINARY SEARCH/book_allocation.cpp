#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> arr, int n, int m, int maxAllowedPages){
    //O(n)
    int std = 1, pages = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > maxAllowedPages){
            return false;
        }
        if(pages + arr[i] <= maxAllowedPages){
            pages += arr[i];
        }
        else{
            std++;
            pages = arr[i];
        }
    }
    return std > m ? false : true;
}

int bookAllocate(vector<int> arr, int n, int m){
    // O(logN*n + n) = logN*n
        if(m>n){
            return -1;
        }
        int sum = 0, maxVal = arr[0];

        for(int i = 0; i < n; i++)
        {
            maxVal = (maxVal, arr[i]);
            sum += arr[i];
        }

        int ans = -1;
        int st = 0, end = sum, mid;
        // Binary search ka logic
        while(st <= end){ // O(logN * n)
            // N is the range on which B.S. is being applied
            int mid = st + (end-st)/2;
            
            if(isValid(arr, n, m, mid)){//valid(move left)
                end = mid-1;
                ans = mid;
            }
            else{//Invalid(move right)
                st = mid +1;
            }
        }
        return ans;
    }

int main()
{
    // vector<int> arr = {2, 1, 3, 4};
    // int n = 4, m =2;
    vector<int> arr = {15, 17, 20};
    int n = 3, m =2;
    cout << bookAllocate(arr, n , m)<< endl;
    return 0;
}