#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    if(n == 0 || n == 1){
        cout << "The " << n << " element in the fibonacci series is: " << n << endl;
    }

    //On observing the pattern we need only the prev and the next prev values or points
    int prev = 1;
    int nxtPrev = 0;
    int idx = 2;
    int i;
    while(idx <= n){
        i = prev + nxtPrev;
        nxtPrev = prev;
        prev = i;
        idx++;
    }

    cout << "The " << n << " element in the fibonacci series is: " << i << endl;

}
