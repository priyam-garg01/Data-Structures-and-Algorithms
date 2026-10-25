#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

//for getting only 1 subseq we return true and false from the function
int printAllSubseqWithSumK(int index, int arr[], int n, int sum, int k){
    if(sum > k)return 0;//strictly done if arr contains whole numbers only
    if(index >= n){
        if(sum  == k){
            return 1;
        }
        return 0;
    }
     
   
    sum += arr[index];
    int l = printAllSubseqWithSumK(index + 1, arr, n, sum, k);
       
    
    sum -= arr[index];
  
    int r = printAllSubseqWithSumK(index + 1, arr, n, sum, k);
    
    return l + r;
}

int main(){
    int arr[] = {6, 2, 3, 1, 5};
    vector<int> v;

    int ct = printAllSubseqWithSumK(0, arr, 5, 0, 9);

    cout << ct;
    

    return 0;
}