/*
Definition of doubly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};
*/

class Solution {
public:
    ListNode * deleteAllOccurrences(ListNode* head, int target) {
       ListNode* temp = head;
       while(temp != NULL){
        if(temp->val == target){
            ListNode* prevNode = temp->prev;
            ListNode* nextNode = temp->next;

            if(prevNode)prevNode->next = nextNode;
            if(nextNode)nextNode->prev = prevNode;
            ListNode* delNode = temp;
            delete delNode;
            temp = nextNode;
        }
        else
            temp = temp->next;
       }
       return head;
    }
};