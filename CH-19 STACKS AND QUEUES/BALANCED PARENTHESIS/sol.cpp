/*Given string str containing just the characters '(', ')', '{', '}', '[' and ']', check if the input string 
is valid and return true if the string is balanced otherwise return false.

Example 1
Input: str = “()[{}()]”
Output: True
Explanation: As every open bracket has its corresponding close bracket. Match parentheses are in correct 
order hence they are balanced.*/
class Solution {
public:
    bool isValid(string str) {
       stack <char> st;

       for(int i = 0; i < str.size(); i++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
            st.push(str[i]);//if an opening bracket is encountered push it into the stack
        }
        else{//if closing bracket encountered;
            if(st.empty())return false;
            
            else{
                char ch = st.top();
                st.pop();
                if(str[i] == '(' && ch == ')')
                continue;
                else if(str[i] == '[' && ch == ']')continue;
                else if(str[i] == '{' && ch == '}')continue;
            }

        }
       }
       if(st.empty())return true;//at last if anything is present in the stack string is unbalanced
       else return false;
    }
};
/*T.C. = O(N), S.C. = O(N/2)WRONG!!*/as we store only the opening brackets but string may only contain opening brackets
//S.C. = O(N)