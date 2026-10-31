/*Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.

Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".

 

Example 1:

Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.
Example 2:

Input: a = "a", b = "aa"
Output: 2
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist of lowercase English letters.*/
class Solution {
public:
    vector<int> Lps(string s){//O(M)
        vector<int> LPS(s.size(), 0);

    int pre = 0; int suf = 1;
    while(suf < s.size()){
        if(s[pre] == s[suf]){
            LPS[suf] = pre + 1;
            pre++;
            suf++;
        }
        else{
            if(pre != 0){
                pre = LPS[pre-1];
            }
            else{
                LPS[suf] = 0;
                suf++;
            }
        }
        }
        return LPS;
    }
    int repeatedStringMatch(string a, string b) {
        int n1 = a.size();//n
        int n2 = b.size();//m
        if(a == b)return 1;
       string s;
    //    int size = (n2+n1-1)/n1;//We copy the string enough number of times such that we can find the string b in that

    //    while(size){
    //         s += a;
    //         size--;
    //    }
    //     size = (n2+n1-1)/n1;
        //Instead of this whole calc we can simply condition while loop to have size of s < b
    int repeat = 0;
    while(s.size() < b.size()){
        s += a;
        repeat++;
    }
       vector<int> LPS = Lps(b);


    for(int k = 0; k <= 1; k++){//We do not know if string matches in size rep or size + 1 rep if b size is a multiple of string
        
        int i = 0;
        int j = 0;
        if(k == 1)s += a;
        
    while(i < s.size() && j < n2){
        if(s[i] == b[j]){
            i++;
            j++;
            if(j == n2)return repeat + k;
        }
        else{
            if(j != 0){
                j = LPS[j-1];
            }
            else{
                i++;
            }
        }
    }
    }


    return -1;
        
    }
};/*T.C. = O(M + N) + O(M) + O(M + N) == O(M + N), S.C. = O(M + N)*/