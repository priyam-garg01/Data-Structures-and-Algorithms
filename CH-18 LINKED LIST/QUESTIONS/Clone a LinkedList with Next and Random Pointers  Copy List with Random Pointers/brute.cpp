/*A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
//wrong approach !!!!
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node* temp = head;
        Node* dummyNode = new Node(-1);
        Node* newNode = dummyNode;
        /*
        while(temp != NULL){
            newNode->next = new Node(temp->val);
            newNode = newNode->next;
            newNode->random = temp->random;
            //we cannot use the same logic of singly linked list becz the node that random pointer is pointing to has not yet been created
            temp = temp->next;
        }
        */
//Firstly we will create the nodes with val and next ptr; type of a singly linke dlist is created
    while(temp != NULL){
        newNode->next = new Node(temp->val);
        newNode = newNode->next;
        temp = temp->next;
    }
    newNode = dummyNode->next;
    temp = head;
    while(temp != NULL){
        newNode->random = temp->random;
        //does not make the copied list independent. It simply copies the address of the original node.
        newNode = newNode->next;
        temp = temp->next;
    }
    /*Original:
A -> B -> C
|         ^
+---------+

(random of A points to C)

After your code:

Copied:
A' -> B' -> C'
 |
 +---------> C   (original node, NOT C')
 
 The copied node A' is still pointing into the original list, which is incorrect.*/
 
        return dummyNode->next;
    }
};




/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;//If there is only one node, returning head returns the original node, not a copy. so only works if head is null if one element the copy will be made and then returned
        }
        Node* temp = head;
        
//Using a hashmap store the nodes of LL and make its copy too
    unordered_map <Node*, Node*> mpp;
    while(temp != NULL){
        Node* newNode = new Node(temp->val);
        mpp[temp] = newNode;
        temp = temp->next;
    }
    //all the nodes are stored along with its copy
        temp = head;
        //No need to make a new list you can return the head of copied list from the map itself
        /*
        Node* dummyNode = new Node(-1);
        Node* copyList = dummyNode;
       */
    while(temp != NULL){
        mpp[temp]->next = mpp[temp->next];//temp->next and temp->random point to original nodes, not the copied nodes.
        mpp[temp]->random = mpp[temp->random];
        // copyList->next = mpp[temp];
        // copyList = copyList->next;
        temp = temp->next;
    }
    
        // return dummyNode->next;
        return mpp[head];
    }
    /*We have to return the copy of the linked list and not return any part of the OG LL so be careful: Store the nodes and their copies in a map and connect the required pointer positions in the second loop and return head of mpp and not head(OG)
T.C. = O(2NLOGN) OR O(2N), S.C. = O(N)
*/
};

