/*Given a sorted dictionary of an alien language having N words and K starting alphabets of a standard dictionary. Find the order of characters in the alien language.

There may be multiple valid orders for a particular test case, thus you may return any valid order as a string. The output will be True if the order returned by the function is correct, else False denoting an incorrect order. If the given arrangement of words is inconsistent with any possible letter ordering, return an empty string "".


Example 1

Input: N = 5, K = 4, dict = ["baa","abcd","abca","cab","cad"]



Output: b d a c



Explanation: 

We will analyze every consecutive pair to find out the order of the characters.

The pair “baa” and “abcd” suggests ‘b’ appears before ‘a’ in the alien dictionary.

The pair “abcd” and “abca” suggests ‘d’ appears before ‘a’ in the alien dictionary.

The pair “abca” and “cab” suggests ‘a’ appears before ‘c’ in the alien dictionary.

The pair “cab” and “cad” suggests ‘b’ appears before ‘d’ in the alien dictionary.

So, [‘b’, ‘d’, ‘a’, ‘c’] is a valid ordering.

Example 2

Input: N = 3, K = 3, dict = ["caa","aaa","aab"]



Output: c a b



Explanation: Similarly, if we analyze the consecutive pair 

for this example, we will figure out [‘c’, ‘a’, ‘b’] is 

a valid ordering.*/
class Solution {
public:
	string findOrder(string dict[], int N, int K) {
		vector<vector<int>> adj(K);
    //from here we make an adj list on who appears before whom
        for(int i = 0; i < N - 1; i++){
            int j = 0; int k = 0;
            //1. (edge case)The Prefix Case (Larger word before smaller word)
            bool mismatch = false;
            

            while(j < dict[i].size() && k < dict[i + 1].size()){
                if(dict[i][j] == dict[i + 1][k]){
                    j++;
                    k++;
                }
                else if(dict[i][j] != dict[i + 1][k]){
                    adj[dict[i][j] - 'a'].push_back(dict[i + 1][k] - 'a');
                    break;
                }
        if(!mismatch && dict[i].size() > dict[i + 1].size())return "";
            }
        }
            vector<int> inDeg(K);
            for(int i = 0; i < K; i++){
                for(auto it : adj[i]){
                    inDeg[it]++;
                }
            }
            queue<int> q;
            for(int i = 0; i < K; i++){
                if(inDeg[i] == 0){
                    q.push(i);
                }
            }
            string ans;
            // 2. (edge case)The Cycle Case (Topo sort size < K)
        while(!q.empty()){
            char node = 'a' + q.front();
            ans.push_back(node);
            q.pop();
            for(auto it : adj[node - 'a']){
                if(inDeg[it])inDeg[it]--;
                if(inDeg[it] == 0)q.push(it);
            }
        }
        if(ans.size() == adj.size())return ans;
        return "";
	}
};
// T.C. = O(N*STRING SIZE) + T.C. AND S.C. SAME AS TOPO SORT