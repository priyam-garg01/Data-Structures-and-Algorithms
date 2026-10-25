class Solution {
public:
unordered_map<string, int> mpp;//Stores the word along with the level it is present in the vector of strings of beginWord to endWord 
vector<vector<string>> ans;
string b;//beginWord to pass in rec

    void dfs(string word, vector<string>& seq){
        if(word == b){
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());//to add other seq while backtracking
            return;
        }
        for(int i = 0; i < word.size(); i++){
                char c = word[i];
                int steps = mpp[word];
                for(char p = 'a'; p <= 'z'; p++){
                    word[i] = p;
    if(mpp.find(word) != mpp.end() && mpp[word]  + 1 == steps){
        seq.push_back(word);
        dfs(word, seq);
        seq.pop_back();//While backtracking
    }
                }
                word[i] = c;
            }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st;
        for(int i = 0; i < wordList.size(); i++){
            st.insert(wordList[i]);
        } 
        b = beginWord;
        queue<string> q;//From word ladder 1
        q.push(beginWord);
        st.erase({beginWord});

        int size = beginWord.size();
        mpp[beginWord] = 0;
        while(!q.empty()){
            string word = q.front();
            q.pop();
            if(word == endWord)break;
            for(int i = 0; i < word.size(); i++){
                char c = word[i];
                int steps = mpp[word];
                for(char p = 'a'; p <= 'z'; p++){
                    word[i] = p;
                    if(st.count(word)){
                       q.push(word);
                       st.erase(word);
                       mpp[word] = steps + 1;
                    }
                }
                word[i] = c;
            }
        }
        //After filling the map we check if we reach the end word
        if(mpp.find(endWord) != mpp.end()){
            vector<string> seq;//to store the ans
            seq.push_back({endWord});
            dfs(endWord, seq);
        }

    return ans;
    }
};/*We first do a bfs traversal to store the path in the map along with the level number 
then unlike in the brute force where there was MLE as we were travelling many paths to reach the endWord; 
Here we tarvel from the endWord to the beginWord using a dfs traversal while using backtracking and reversing 
the vector when pushing into the ans and reversing it back to store 
other ans else the wrong word will be popped back*/