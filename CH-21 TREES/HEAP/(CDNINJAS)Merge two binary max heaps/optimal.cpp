#include <bits/stdc++.h> 
void maxHeapify(vector<int>& arr, int i, int n){
    int lg = i;

    int left = 2*i + 1;
    int right = 2*i + 2;

    while(i < n){
        if(left < n && arr[left] > arr[lg])lg = left;
        if(right < n && arr[right] > arr[lg])lg = right;

        if(lg != i){
            swap(arr[lg], arr[i]);
            i = lg;
            left = 2*i + 1;
            right = 2*i + 2;
        }
        else break;
    }

}
void buildMaxHEap(vector<int>& arr, int n){
    for(int i = n/2-1; i >= 0; i--){
        maxHeapify(arr, i, n);
    }
}
vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2) {
        vector<int> mergedHeap;
        
        for(int i = 0; i < n; i++){
            mergedHeap.push_back(arr1[i]);
        }

        for(int j = 0; j < m; j++){
            mergedHeap.push_back(arr2[j]);
        }

        buildMaxHEap(mergedHeap, n + m);

    return mergedHeap;
}//T.C. = O(2*(N + M)), S.C. = O(2*(N + M))