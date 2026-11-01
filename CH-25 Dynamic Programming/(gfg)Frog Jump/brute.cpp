#include<bits/stdc++.h>
using namespace std;
/*Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the last stair.

From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs.

Determine the minimum total cost required for the frog to reach the last stair.

Example:

Input: heights[] = [20, 30, 40, 20]
Output: 20
Explanation: Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
jump from stair 0 to 1: cost = |30 - 20| = 10
jump from stair 1 to 3: cost = |20 - 30| = 10
Total Cost = 10 + 10 = 20
Input: heights[] = [30, 20, 50, 10, 40]
Output: 30
Explanation: Minimum cost will be incurred when frog jumps from stair 0 to 2 then 2 to 4:
jump from stair 0 to 2: cost = |50 - 30| = 20
jump from stair 2 to 4: cost = |40 - 50| = 10
Total Cost = 20 + 10 = 30
Constraints:

1 ≤ height.size() ≤ 105
0 ≤ height[i] ≤ 104*/
// class Solution {
//   public:
  
//     int findCost(int n, vector<int>& height){
//         if(n < 0)return 1e9;
//         if(n == 0)return 0;
//         if(n == 1)return abs(height[n]-height[n-1]);
        
//         int jump1 = abs(height[n] - height[n-1]);
//         int jump2 = abs(height[n] - height[n-2]);
        
//         return min(jump1 + findCost(n-1, height), jump2 + findCost(n-2, height));
//     }
  
//     int minCost(vector<int>& height) {
//         int n = height.size() - 1;
        
//         return findCost(n, height);
//     }//T.C. = O(2^N), S.C. = O(N)
// };

class Solution {
  public:
  
    int findCost(int idx, vector<int>& height){
        if(idx == 0)return 0;
   
        int left = findCost(idx-1, height) + abs(height[idx] - height[idx-1]);
        int right = 1e9;
        if(idx>1)right = findCost(idx-2, height) + abs(height[idx] - height[idx-2]);
    
        
        return min(left, right);
    }
  
    int minCost(vector<int>& height) {
        int n = height.size();
        
        
        return findCost(n-1, height);
    }
};