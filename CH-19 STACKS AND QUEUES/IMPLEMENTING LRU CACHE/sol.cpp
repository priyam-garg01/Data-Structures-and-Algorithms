/*Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4*/
 class Node{
        public://nodes and ptrs should be made public to use in other classes
        int key;
        int val;
        Node* next;
        Node* back;
        Node(): key(-1), val(-1), next(nullptr), back(nullptr){};
        Node(int x, int y): key(x), val(y), next(nullptr), back(nullptr){};
        Node(int x, int y, Node*next1, Node*prev1): key(x) ,val(y), next(next1), back(prev1){};
    };
class LRUCache {
public:
    int n;
    Node*dummyHead = new Node(-1, -1);
    Node*dummyTail = new Node(-1, -1);
    LRUCache(int capacity) {
    dummyHead->next = dummyTail;
    dummyTail->back = dummyHead;
        n = capacity;
    }
    void insertAfterHead(Node* node){
        node->next = dummyHead->next;
        node->back = dummyHead;
        dummyHead->next->back = node;
        dummyHead->next = node;
    }
    void deleteNode(Node* node){
        // Node* delNode = node;
        node->back->next = node->next;
        node->next->back = node->back;
        // delete(node);
        // when moving forward we de not need to destroy it 
    }
    unordered_map<int, Node*> mpp;
    
    
    int get(int key) {
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
        //this node is LRU so put at front
        deleteNode(node);
        insertAfterHead(node);
            return node->val;
        }
        else return -1;
    }
    
    void put(int key, int value){
        if(mpp.find(key) != mpp.end()){
        Node* node = mpp[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
        }

       else{
        if(mpp.size() == n){
            Node* delNode = dummyTail->back;
            mpp.erase(delNode->key);
            deleteNode(delNode);

        }
       //After removing inserting the newNode
       Node* newNode = new Node(key, value);
       mpp[key] = newNode;
       insertAfterHead(newNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
/*Use a doubly linked list to store the key value pairs as nodes and the least recently used will be closest to the dummyHead and tail , 
Keep updating the map with key and Node addresses to get the value of particular key by accessing the node*/
// T.C. = O(1), S.C. = O(CAPACITY){FOR MAP};