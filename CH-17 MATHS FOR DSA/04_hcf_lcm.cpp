#include <iostream>
using namespace std;

int gcdNum(int n1, int n2){
    if(n1 == 0) return n2;
    if(n2 == 0) return n1;
    if(n1 == n2) return n1;
    int gcd = 1;
    for(int i = 2; i <= min(n1, n2); i++){
        if(n1 % i == 0 && n2 % i == 0){
            gcd = i;
        }
    }
    return gcd;
}
int gcdNumEuclid(int n1, int n2){
    if(n1 == 0) return n2;
    if(n2 == 0) return n1;
    if(n1 == n2) return n1;
    int gcd = 1;
    if( n1 > n2){
        // n1 = n1 - n2;
        // better approach
        n1 = n1 % n2;

    }
    if(n1 < n2){
        // n1 = n1 - n2;
        // better approach
        n2 = n2 % n1;
    }
    gcd = gcdNumEuclid(n1, n2);
     
    return gcd;
}

int lcm(int a , int b){
    int gcd = gcdNumEuclid(a, b);
    return (a*b) / gcd;
    // a*b = lcm*gcd;
}
int main()
{
    int n1 = 0, n2 =866;
    cout << gcdNumEuclid(n1, n2);
    return 0;
}