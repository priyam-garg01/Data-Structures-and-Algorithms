#include<bits/stdc++.h>
using namespace std;

int fib(int n, int dp[]){
    if(n == 1 || n == 0){//Base Case
        return dp[n] = n;
    }

    if(dp[n] != -1) return dp[n];
    return dp[n] = fib(n-1, dp) + fib(n-2, dp);
}


int main(){
    int n;
    cin >> n;
    int dp[n + 1];
    for(int i = 0; i <= n; i++){
        dp[i] = -1;
    }

    int fibN = fib(n, dp);
    cout << "The " << n << " element in the fibonacci series is: " << fibN << endl;
//T.C. = O(N){Only reach each entry once}, S.C. = O(N + N){Recursive stack space + dp arr}
    return 0;
}