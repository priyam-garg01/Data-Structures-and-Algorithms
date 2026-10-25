/*In a magic event, you are given ‘N’ bags, each bag containing ‘A[i]’ chocolates. In one unit of time, you can choose any bag ‘i’ and eat all the chocolates ‘A[i]’ in that bag and then the magician fills the ith bag with floor(‘A[i]’ / 2) chocolates. Your task is to find the maximum number of chocolate you can eat in ‘K’ units of time.

Since the answer could be large, return answer modulo 10^9 + 7.

For Example:
For the array [ 4, 7, 9, 10] and ‘k’=2
In the first step, we can choose the last bag. So the answer will be 10 and the array will be [4, 7, 9, 5].
In the second step, we can choose the second last bag. So the answer will be 19 and the array will be [4, 7, 4, 5].
So the final output will be 19.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
1 <= N <= 10^5
1 <= ARR[i] <= 10^5

It is guaranteed that the sum of ‘N’ over all test cases doesn’t exceed 10^5.*/

#include <bits/stdc++.h> 
int maximumChocolates(vector<int> &arr, int k){
    int modulo = 1e9 + 7;
    int n = arr.size();
    priority_queue<int> pq;


    for(int i = 0; i < n; i++){
        pq.push(arr[i]);
    }
    int ct = 0;
    long long chocoCt = 0;
    while(ct != k && pq.top() > 0){
        long long maxi = pq.top();
        pq.pop();
        chocoCt = (chocoCt+maxi)%modulo;
        maxi = maxi/2;
        pq.push(maxi);
        ct++;
    }
    int ans = chocoCt%modulo;
    return ans;
}//T.C. = O(NLOGN), S.C. = O(2N)