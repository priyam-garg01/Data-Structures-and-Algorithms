/*Given a string s consisting of only uppercase and lowercase characters. The task is to sort uppercase and lowercase letters separately such that if the ith place in the original string had an Uppercase character then it should not have a lowercase character after being sorted and vice versa.

Examples :

Input: s = "GEekS"
Output: EGekS
Explanation: Sorted form of given string with the same case of character will result in output as EGekS.
Input: s = "XWMSPQ"
Output: MPQSWX
Explanation: Since all characters are of the same case We can simply perform a sorting operation on the entire string.
Constraints:

1 ≤ s.size() ≤ 105*/
class Solution {
  public:
    string caseSort(string& s) {
        int n = s.size();
        
        vector<int> upper(26, 0);
        vector<int> lower(26, 0);
        
        string ans;
        for(int i = 0; i < n; i++){
            if(s[i] > 90){
                lower[s[i] - 'a']++;
                ans += '/';
            }
            else{
                upper[s[i] - 'A']++;
                ans += '#';
            }
        }
        
        //Sort the uppercase
        string up;
        for(int i = 0; i < 26; i++){
            char c = i + 'A';
            while(upper[i]){
                up += c;
                upper[i]--;
            }
        }
        //Sort the lowercase
        string low;
        for(int i = 0; i < 26; i++){
            char c = i + 'a';
            while(lower[i]){
                low += c;
                lower[i]--;
            }
        }
        int i = 0;
        int j = 0; 
        int k = 0;
        
        while(i < n){
            if(ans[i] == '/'){
                ans[i] = low[j];
                j++;
            }
            else{
                ans[i] = up[k];
                k++;
            }
            i++;
        }
        
        return ans;
    }
};/*T.C. = O(4N), S.C. = O(2N)*/