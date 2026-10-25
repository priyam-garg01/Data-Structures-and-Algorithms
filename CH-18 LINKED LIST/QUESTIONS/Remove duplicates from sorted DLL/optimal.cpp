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
    ListNode * removeDuplicates(ListNode *head) {
if(head == NULL || head->next == NULL){
    return head;
}
    ListNode* temp = head;
    ListNode* nextNode = head->next;

    while(nextNode != NULL){
        if(temp->val == nextNode->val){
            ListNode*delNode = nextNode;
            nextNode = nextNode->next;
            temp->next = nextNode;
            if(nextNode)nextNode->prev = temp;
            delete delNode;
        }
        else{
            temp = nextNode;
            nextNode = nextNode->next;
        }
            
    }

        return head;
    }
};/*Duplicate nodes will also be present in sorted order so keep deleting nodes and moving while the next node 
is not null when their data is not equal sjif both of them by one place
T.C. = O(N)*/