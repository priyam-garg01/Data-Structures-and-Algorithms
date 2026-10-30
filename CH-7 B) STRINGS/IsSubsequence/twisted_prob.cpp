/*How would you handle a follow-up scenario where there are many incoming s strings(s1, s2, s3, ... sk) to 
check against a fixed t
*/
/*My sol: iterate throgh all of them
Iterating linearly for each string takes O(K×∣T∣) time, which is inefficient when ∣T∣ is very large. 
How can you pre-process t (e.g., storing character indices) so each search takes O(∣Si∣log∣T∣) time
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<char, vector<int>> mp;

    // Preprocessing fixed string t
    Solution(string t) {
        for (int i = 0; i < t.size(); i++) {
            mp[t[i]].push_back(i);
        }
    }

    bool isSubsequence(string s) {
        int prev = -1;//Index of previously matched char in t

        for(int i = 0; i < s.size(); i++){
            if(mp.find(s[i]) == mp.end()){
                return false;//First char is only not found
            }
            //To find the next occurence we have to update prev 
            auto it = upper_bound(mp[s[i]].begin(), mp[s[i]].end(), prev);
            //It performs a binary search to find the index stricly greater than prev to avoid any previous indices char comparison
        
            if(it == mp[s[i]].end()){//no index found
                return false;
            }
            prev = *it;
        }
        return true;
    }
};

int main() {
    string t;
    cin >> t;

    Solution obj(t);

    int k;
    cin >> k;

    while (k--) {
        string s;
        cin >> s;

        cout << (obj.isSubsequence(s) ? "True" : "False") << endl;
    }

    return 0;
}