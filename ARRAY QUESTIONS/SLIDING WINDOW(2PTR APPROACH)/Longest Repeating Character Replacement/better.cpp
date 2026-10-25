class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxL = 0;
    unordered_map<char, int>hash;//notes the freq of characters
        int maxF = 0;

        int l = 0; int r = 0;
        char c;
        while(r < n){
            hash[s[r]]++;
            if(hash[s[r]] > maxF){
                maxF = max(maxF, hash[s[r]]);
                // c = s[r];
            }
            int changes = (r - l + 1) - maxF; 

            while(changes > k){
                // if(s[l] == c){
                //     maxF--;
                // }
                    hash[s[l]]--;
                    l++;
                    changes = r - l + 1 - maxF;
            }
            if(changes <= k){
                maxL = max(maxL, r - l + 1);
            }
                r++;
        }
        return maxL;
    }
};/*Optimal:
T.C. = O(2N), S.C. = O(26)
 /*We donot need to decrease maxF as there might some some charc with equal 
 maxF so by decrementing it we submit an incorrect ans by -1 of OG ans and that char c might be that 
 maxF charcter which is ame as that occurring as second last element by freq*/