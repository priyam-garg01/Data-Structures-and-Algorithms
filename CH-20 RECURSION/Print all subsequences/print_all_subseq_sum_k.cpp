#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void printAllSubseqWithSumK(int index, vector<int> &v, int arr[], int n, int sum, int k){
if(sum > k)return;//strictly done if arr contains whole numbers only
    if(index >= n){
        if(sum  == k){
            for(auto it : v){
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }
     
    v.push_back(arr[index]);
    sum += arr[index];
    printAllSubseqWithSumK(index + 1, v, arr, n, sum, k);

    sum -= arr[index];
    v.pop_back();
    printAllSubseqWithSumK(index + 1, v, arr, n, sum, k);
}

int main(){
    int arr[] = {6, 2, 7, 1, 5};
    vector<int> v;
    printAllSubseqWithSumK(0, v, arr, 5, 0, 7);


    return 0;
}