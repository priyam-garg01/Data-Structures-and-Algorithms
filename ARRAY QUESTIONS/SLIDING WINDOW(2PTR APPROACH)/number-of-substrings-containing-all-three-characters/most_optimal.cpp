class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> lastSeen(3, -1);//0, 1, 2, represent the charcters a, b, c's and we store their lastSeen index values in this vector
        //map stores the index of the last occurred characters
        int ct = 0;
        
        for(int i = 0; i < n; i++){
            lastSeen[s[i] - 'a'] = i;

if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
    int index = min({lastSeen[0],lastSeen[1],lastSeen[2]});//std::min doesn't have a 3-argument overload — it only 
    // takes two arguments (or an initializer_list). Passing three arguments like this won't compile.
// Fix: use the initializer-list version, std::min({a, b, c}):
    ct += index + 1;
}
        }
            return ct;
    }
};/*MOST OPTIMAL:
Store the last seen indices in the vector of char a, b, c
We will see the end point of the string and if it contains all three character we increment count by the min of the last seen indices of the characters + 1 which will count the present and the behind substrings
T.C. = O(N), S.C. = O(1)*/