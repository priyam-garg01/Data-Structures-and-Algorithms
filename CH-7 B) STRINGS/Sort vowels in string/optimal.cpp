class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        string t;

        vector<int> upper(26, 0); 
        vector<int> lower(26, 0);

    //Store the vowels and consonants separately
        for(int i = 0; i < n; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o'|| s[i] == 'u'){
                t.push_back('#');
                lower[s[i] - 'a']++;
            }
            else if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O'|| s[i] == 'U'){
                t.push_back('#');
                upper[s[i] - 'A']++;
            }
            else t.push_back(s[i]);
        }

    //Sort the vowels
        string vowel;

        //Uppercase
        for(int i = 0; i < 26; i++){
            char c = 'A' + i;
            while(upper[i]){
                vowel += c;
                upper[i]--;
            }
        }

        //Lowercase
        for(int i = 0; i < 26; i++){
            char c = 'a' + i;
            while(lower[i]){
                vowel += c;
                lower[i]--;
            }
        }


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
};/*T.C. = O(4N), S.C. = O(52 + N + K) = O(N + K)*/