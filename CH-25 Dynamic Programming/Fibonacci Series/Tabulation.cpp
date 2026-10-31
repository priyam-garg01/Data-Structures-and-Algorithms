#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int dp[n + 1];
    //Initiating base cases
    dp[0] = 0;
    dp[1] = 1;

    int id = 2;
    while(id <= n){
        dp[id] = dp[id - 1] + dp[id - 2];
        id++;
    }

    cout << "The " << n << " element in the fibonacci series is: " << dp[n] << endl;
    //T.C. = O(N){Only reach each entry once}, S.C. = O(N){dp arr}
    return 0;
}