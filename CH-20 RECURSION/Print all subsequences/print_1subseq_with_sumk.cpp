#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

//for getting only 1 subseq we return true and false from the function
bool printAllSubseqWithSumK(int index, vector<int> &v, int arr[], int n, int sum, int k){
    if(sum > k)return false;//strictly done if arr contains whole numbers only
    if(index >= n){
        if(sum  == k){
            for(auto it : v){
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }
     
    v.push_back(arr[index]);
    sum += arr[index];
    if(printAllSubseqWithSumK(index + 1, v, arr, n, sum, k)){
        return true;
    }
    sum -= arr[index];
    v.pop_back();
    if(printAllSubseqWithSumK(index + 1, v, arr, n, sum, k)){
        return true;
    }
    else{
    return false;//if no subseq is found
    }
}

int main(){
    int arr[] = {6, 2, 3, 1, 5};
    vector<int> v;
    if(!printAllSubseqWithSumK(0, v, arr, 5, 0, 17))
        cout << "No subseq found!!"<< endl;

    return 0;
}