/*
Given a special linked list containing n head nodes where every node in the linked list contains two pointers:

‘Next’ points to the next node in the list
‘Child’ pointer to a linked list where the current node is the head
Each of these child linked lists is in sorted order and connected by a 'child' pointer.
Flatten this linked list such that all nodes appear in a single sorted layer connected by the 'child' pointer
and return the head of the modified list.*/
/*
Definition of special linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode()
    {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2)
    {
        val = data1;
        next = next1;
        child = next1;
    }
};
*/

class Solution {
public:
    ListNode* flattenLinkedList(ListNode* &head) {
        ListNode* temp = head;
        //BRUTE FORCE:Store every integer in an arr and make a child linked list;
        vector<int> arr;
        while(temp != NULL){//O(n)
            ListNode* child = temp->child;
                arr.push_back(temp->val);
            while(child){
                arr.push_back(child->val);
                child = child->child;
            }
            temp = temp->next;
        } 
        ListNode* dummyNode = new ListNode(0);
        ListNode* newHead = dummyNode;
        newHead->next = NULL;
        temp = newHead;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); i++){
            ListNode* newNode = new ListNode(arr[i]);
            temp->child = newNode;
            temp = newNode;
        }
        return dummyNode->child;
    }
};/*where k is total nodes = m*n
T.C. = O(K) + O(KLOGK) + O(K)*/