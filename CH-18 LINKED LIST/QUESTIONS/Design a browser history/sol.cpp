/*
You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

Implement the BrowserHistory class:

BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
void visit(string url) Visits url from the current page. It clears up all the forward history.
string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.
 

Example:

Input:
["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
Output:
[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]
*/
    class Node{
        public://nodes and ptrs should be made public to use in other classes
        string val;
        Node* next;
        Node* prev;
        Node(): val("0")/*here string should be used*/, next(nullptr), prev(nullptr){};
        Node(string x): val(x), next(nullptr), prev(nullptr){};
        Node(string x, Node*next1, Node*prev1): val(x), next(next1), prev(prev1){};
    };
    /* DONOT write like this fashion on online compilers 
        Node(){
            val = "-1";
            next = NULL;
            prev = NULL;
        }
        Node(string val1){
            val = val1;
            next = NULL;
            prev = NULL;
        }
        Node(string val1, Node* next1, Node* prev1){
            val = val1;
            next = next1;
            prev = prev1;
        }*/
class BrowserHistory {
public:
    Node*curr;
    BrowserHistory(string homepage) {
        //curr is never declared
        /*
        Node* cur = new Node(homepage);
        */
        curr = new Node(homepage);
    }
    
    void visit(string url) {//visit should clear forward history
    /*
    //for this curr ka next should first point to null
        curr->next = NULL;
       // visit() doesn't actually remove forward history
       *///deleting the forward nodes
       Node* temp = curr->next;
       while(temp != NULL){
        Node* delNode = temp;
        temp = temp->next;
        delete delNode;
       }
       curr->next = NULL;
        Node* newNode = new Node(url, NULL, curr);
        curr->next = newNode;
        curr = newNode;
        
    }
    
    string back(int steps) {
        while(steps){
            if(curr->prev == NULL) break;
            curr = curr->prev;
            steps--;
        }
        return curr->val;
    }
    
    string forward(int steps) {
        while(steps){
            if(curr->next == NULL)break;
            curr = curr->next;
            steps--;
        }
        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

 
/*just use a DS and make the reqd functions code*/