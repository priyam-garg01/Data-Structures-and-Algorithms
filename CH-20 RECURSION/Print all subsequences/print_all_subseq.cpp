#include <iostream>
#include <vector>
using namespace std;


void printAllSubseq(int index, vector<int> &v, int arr[], int n){
    
//base case
    if(index >= n){
        for(auto it : v){
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    v.push_back(arr[index]);
    printAllSubseq(index + 1, v, arr, n);
    //Take or pick that particular element in the subsequence
    v.pop_back();
    printAllSubseq(index + 1, v, arr, n);
    //not pick, or not take that particular element in the subsequence
    /*Reverse can all be done not pick condition first*/

    
    // printAllSubseq(index + 1, v, arr, n);
    // //not pick, or not take that particular element in the subsequence
    
    // v.push_back(arr[index]);
    // printAllSubseq(index + 1, v, arr, n);
    // //Take or pick that particular element in the subsequence
    
}


int main()
{
    
    int arr[] = {3, 6, 9, 2};
    vector<int> v;
    printAllSubseq(0, v, arr, 4);
    // T.C. = O(2^N), S.C. = O(N){RECURSION STACK SPACE};


    return 0;
}