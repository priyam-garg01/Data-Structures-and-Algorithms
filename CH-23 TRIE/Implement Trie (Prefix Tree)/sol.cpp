/*A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 

Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.*/
struct Node{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){//Checks if that node contains that particular key or not
        return(links[ch - 'a'] != NULL);
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;//This means that character predetermined index will point to node which is a new node created in the insert function
    }
    Node* get(char ch){//Return the ptr address pointed by the char index to the new node
        return links[ch - 'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;//To check that if a word is found by checking the last ref node's flag val
    }
};
class Trie {
private: Node* root;
public:
//Initialize your data structure here
    Trie() {
        root = new Node();
    }
//Inserts the new word by putting each char in a separate node and linking that node
    void insert(string word) {//T.C. = O(N)
        Node* node = root;
        for(int i = 0; i < word.length(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            //moves to the reference trie
            node = node->get(word[i]);
        }
//At last the refernce trie will be having no chars and be flagged to true to mark the end
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i < word.length(); i++){
            if(!node->containsKey(word[i]))return false;
            node = node->get(word[i]);
        }
        return node->isEnd();//it might be the prefix while the word may be a bit longer or shorter
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0; i < prefix.length(); i++){
            if(!node->containsKey(prefix[i]))return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */