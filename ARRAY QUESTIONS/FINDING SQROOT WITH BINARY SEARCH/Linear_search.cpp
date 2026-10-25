#include <iostream>
#include <cmath>
using namespace std;

//Powfunc//log(m)
int powF(int n, int m){
    long long anss = 1;
    while(m > 0){
        if(m%2 == 1){
            anss = anss * n;
            m = m-1;
        }
        else{
            n = n*n;
            m = m/2;
        }
    }
}
/*For large input size
we can return 0 for if < n
return 1 if == n;
return 2 if greater than n

*/

int PowF2(int mid, int n, int m){
    long long ansss = 1;

    for(int i = 1; i <= n; i++){
        ansss = ansss * mid;
        if(ansss > n){
            return 2;
        }
    }
    if(ansss == n){
            return 0;
    }
    return 1;
}
//for m root of n use pow(i, m)// its time complexity is logm(base 2).
int Lsq(int n){
        int ans;
    // for loop
    for(int i = 1; i <= n; i++){
        if(i*i <= n){
            ans = i;
        }
        else
            break;//as we reach a number whose sqaure is greater than n
    }

    // //while loop
    // int j;
    // while(j*j<= n){
    //     ans = j;
    // }


    return ans;
}

int Binary_Sq(int n){
    int low = 1;
    int high = n;
    //  We assume low_sq to be less than or equal to n and high_sq to be greater than n
    int ans;
    // low points to a minimum place where ans is possible whereas high points to a place where ans is not possible
        int mid;
    while(low <= high){
        mid = (low + high)/2;
        if(mid*mid == n){
            return n;
        }
        else if(mid*mid <= n){
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}
int main()
{
    int n = 45;
    int p = Binary_Sq(n);
    int f = Binary_Sq(33);
    int g = Lsq(78);
    cout << p << endl;
    cout << f << endl;
    cout << g << endl;
    
    return 0;
}