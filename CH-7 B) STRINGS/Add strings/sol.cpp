/*Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

 

Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"
Example 2:

Input: num1 = "456", num2 = "77"
Output: "533"
Example 3:

Input: num1 = "0", num2 = "0"
Output: "0"
 

Constraints:

1 <= num1.length, num2.length <= 104
num1 and num2 consist of only digits.
num1 and num2 don't have any leading zeros except for the zero itself.*/
class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();

        string ans;
        int i = n1 - 1;
        int j = n2 - 1;
        int carry = 0;
        while(i >= 0 && j >= 0){
            int sum = num1[i] - '0' +  num2[j] - '0' + carry;

            if(sum > 9)carry = 1;
            else carry = 0;
            // carry = sum/10;

            char o = sum%10 + '0';
            ans.push_back(o);
            i--; 
            j--;
        }

        while(i >= 0){
            int sum = num1[i] - '0' + carry;

            if(sum > 9)carry = 1;
            else carry = 0;
            // carry = sum/10;

            char o = sum%10 + '0';
            ans.push_back(o);
            i--;
        }

        while(j >= 0){
            int sum = num2[j] - '0' + carry;

            if(sum > 9)carry = 1;
            else carry = 0;
            // carry = sum/10;

            char o = sum%10 + '0';
            ans.push_back(o);
            j--;
        }
        if(carry)ans.push_back('1');

        //Reverse the string
        int size = ans.size();
        for(int i = 0; i < size/2; i++){
            swap(ans[i], ans[size - 1 - i]);
        }

        return ans;
    }
};/*T.C. = O(N1 + N2 + MAX{(N1 + N2)/2}), S.C. = O(MAX(N1 + N2))*/