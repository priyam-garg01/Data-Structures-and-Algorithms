class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        string t;

        string vowel;
        for(int i = 0; i < n; i++){
            char c = tolower(s[i]);
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o'|| c == 'u'){
                t.push_back('#');
                vowel.push_back(s[i]);
            }
            else t.push_back(s[i]);
        }
        sort(vowel.begin(), vowel.end());
        int v = 0;
        int i = 0;

        while(i < t.size() && v < vowel.size()){
            if(t[i] == '#'){
                t[i] = vowel[v];
                v++;
            }
            i++;
        }
        return t;
    }
};/*T.C. = O(2N + KLOGK), S.C. = O(K + N)*/