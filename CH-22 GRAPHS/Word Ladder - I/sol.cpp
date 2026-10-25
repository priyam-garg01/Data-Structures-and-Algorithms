/*A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //The wordList contains words adj to which they have a difference of 1 char

        //we need to reach the endWord if present in the list starting from the beginWord which may or may not be present in the wordList 

        
        //As we need to find the morphed word from the wordList we initiate a set and put all strings in that so that we can use the set.find( ) function

        unordered_set<string> st;//O(N)
        for(int i = 0; i < wordList.size(); i++){//O(N)
            st.insert(wordList[i]);//O(LOG(N))
        }
        // could be done by 
 //       unordered_set<string> st(wordList.begin(), wordList.end());O(N*K*logn)


        queue<pair<string, int>> q;//We store it in pair to note the distance from every word

        q.push({beginWord, 1});

    if(st.find(beginWord) != st.end())st.erase(beginWord);
        //O(log(N))

        while(!q.empty()){//O(N), S.C. = O(N)
            string s = q.front().first;
            int words = q.front().second;
            if(s == endWord)return words;
            q.pop();
            for(int i = 0; i < s.size(); i++){//O(K) word length
                char c = s[i];//The char to be changed
                for(int j = 0; j < 26; j++){//O(1)
        //We can also use for(char p = 'a'; p <= 'z'; p++)

                    if(c == 'a' + j)continue;
                    
                    else{
                        s[i] = 'a' + j;
                    if(st.find(s) != st.end()){
                        q.push({s, words + 1});
                        st.erase(s);
                        }
                    }
                }
                //At the end of the inner loop we restore the og word
                s[i] = c;
            }
        }//T.C. = O(N)*O(26*K)*O(LOGN){if set is ordered}
        //S.C. = O(2N)
    //If q becomes empty
    return 0;
    }//T.C. = O(N*K*log(N)), S.C. = O(N)
};/*/*BRUTE FORCE: changing every char of the word and putting a-z in that except that char
        If we find the word in the wordList we process that word
        since many words can be formed that are found in the wordList; This is a bfs traversal which is operated with the use of a q ds
T.C. = O(N*K*log(N)), S.C. = O(N)*/