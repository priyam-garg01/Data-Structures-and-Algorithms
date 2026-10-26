/*Given an integer n, find its factorial. Return a list of integers denoting the digits that make up the factorial of n.

Examples:

Input: n = 5
Output: [1, 2, 0]
Explanation: 5! = 1*2*3*4*5 = 120
Input: n = 10
Output: [3, 6, 2, 8, 8, 0, 0]
Explanation: 10! = 1*2*3*4*5*6*7*8*9*10 = 3628800
Input: n = 1
Output: [1]
Explanation: 1! = 1 
Constraints:

1 ≤ n ≤ 103*/
class Solution {
  public:
  
    vector<int> factorial(int n) {
        vector<int> ans;
        int num = n;
        
        ans.push_back(1);
        int carry  = 0;
        int size = ans.size();
        
        while(num > 1){
            
            for(int i = 0; i < size; i++){
                int product = ans[i] * num + carry;
                carry = product/10;
                
                ans[i] = product % 10;
            }
            
            while(carry){
                ans.push_back(carry % 10);
                carry /= 10;
            }
            size = ans.size();
            num--;
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
    }
};//T.C. = O(n*n) == T.C. = O(1), S.C. = O(N) == O(1)