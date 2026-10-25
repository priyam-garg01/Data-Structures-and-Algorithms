/*Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.*/
class Solution {
public:

bool palindrome(string s, int st, int end){
    while(st <= end){
        if(s[st++] != s[end--])return false;
    }
    return true;
}
void findPalindromeString(string s, int index,  vector<vector<string>> &ans, vector<string> &ds, int n){
    if(index == n){
        ans.push_back(ds);
        return;
    }
   for(int i = index; i < n; i++){
        if(palindrome(s, index, i))//string, start, end is served to the function
        {
            ds.push_back(s.substr(index, i - index  + 1));//starting point and length of string to be pushed
            findPalindromeString(s, i + 1, ans, ds, n);
            ds.pop_back();
        }
   }

}
    vector<vector<string>> partition(string s) {
        int n = (int)s.size();
        vector<vector<string>> ans;
        vector<string> ds;

        findPalindromeString(s, 0, ans, ds, n);

        return ans;
        
    }
};/*We can create partitions by checking if the substring {by giving the string, starting ending indices} and then push them in ds
T.C. = O(N*(N/2)), S.C. = O(n^2){256^2 = 2^64}{as every possible combination can be made}
*/