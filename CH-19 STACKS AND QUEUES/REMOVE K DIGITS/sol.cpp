/*Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        
        if(k >= n)return "0";
        
        stack<char> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && k && st.top() > num[i]){
                st.pop();
                k -= 1;
            }
                st.push(num[i]);
        }

        //case when k is still greater than zero means still elements are to be removed {"123456", k = 3}
        while(k){//O(K)
            st.pop();
            k -= 1;
        }
        if(st.empty())return "0";

        string s;
       while(!st.empty()){//O(N-K)
            // s = s + st.top();
            //concatenation creates a new string every time memory limit exceeds
            s.push_back(st.top());
            st.pop();
       }


       //we get the reversed string 
    //    Now if we get zeroes at front of our ans it will be at the back of our reversed ans which we need to remove
        while(s.size() != 0 && s.back() == '0'){//O(P)P ZEROES
            s.pop_back();
        }
        if(s.size() == 0)return "0";
        for(int i = 0; i < s.size()/2; i++){//O(N-P)/2
            swap(s[i], s[s.size()-i-1]);//s[n-i]xxx s[n-i-1]
        }
    return s;
    }
};/*we will take the numbers in stack one by one if we find a number smaller then that will be removed from the ans string as well
T.C. = O(N){LOOP} + O(K) + O(N-K) + O(N) = O(4N), S.C. = O(N) + O(N) = O(2N)*/