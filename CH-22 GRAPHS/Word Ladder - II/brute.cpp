/*A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 5
endWord.length == beginWord.length
1 <= wordList.length <= 500
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
The sum of all shortest transformation sequences does not exceed 10^5.*/
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //To get the shortest path len we used the bfs traversal
        //Now if we store those nodes in a separate vector

        unordered_set<string> st;
        for(int i = 0; i < wordList.size(); i++){
            st.insert(wordList[i]);//O(N*logk) or O(N*K)
        } 

        queue<vector<string>> q;//This time we do not store the word and the len but the vector of words which is the path to the endWord
        q.push({beginWord});
        vector<vector<string>> ans;
        vector<string> usedOnLevel;//To mark the words as vis once the full level is over as one level may have the same word in its stored list
        usedOnLevel.push_back({beginWord});
        int level = 0;

        while(!q.empty()){//Since we travel level wise there is no chance that any seq of len shorter or equal to the shortest path is not stored
           // O(N)
            vector<string> vec = q.front();
            q.pop();
            // If we already found the shortest paths, and this path is longer, we are done!
            if (!ans.empty() && vec.size() > ans[0].size()) {
                break;
            }
            //erase all the words that has been used in the previous levels to update the set and usedOnLevel
                if(vec.size() > level){
                    level++;
                for(auto it : usedOnLevel){//Complex time
                    st.erase(it);
                }
                usedOnLevel.clear();
            } 
            
            string word = vec.back();
            //store the ans
            if(word == endWord){
                if(ans.size() == 0){
                    ans.push_back(vec);
                }
                else if(vec.size() == ans[0].size()){
                    ans.push_back(vec);
                }
                continue;//skip looking for the transitions fromt he endWord
            }
            for(int i = 0; i < word.size(); i++){//O(26*K)
                char c = word[i];
                for(char p = 'a'; p <= 'z'; p++){
                    word[i] = p;
                    if(st.count(word) > 0){
                       vec.push_back({word});
                       q.push({vec});
                       //mark as vis 
                       usedOnLevel.push_back({word});
                       vec.pop_back();//to put the next matching word
                    }
                }
                word[i] = c;
            }
            
        }

    return ans;
    }
};
