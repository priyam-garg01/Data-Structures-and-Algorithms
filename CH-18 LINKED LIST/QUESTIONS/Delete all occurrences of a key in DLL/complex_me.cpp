/*
Given the head of a doubly linked list and an integer target. Delete all nodes in 
the linked list with the value target and return the head of the modified linked list.

Example 1
Input: head -> 1 <-> 2 <-> 3 <-> 1 <-> 4, target = 1
Output: head -> 2 <-> 3 <-> 4
Explanation: All nodes with the value 1 were removed.
*/
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
        if(head == NULL || head->next == NULL){
            if(head->val == target){
                return NULL;
            }
            return head;
        }
/*If cosecutive heads has target values then a while loop is needed
        if(head->val == target){
            ListNode* delNode = head;
            head = head->next;
            head->prev = NULL;
            delete delNode;
        }
*/
        while(head != NULL && head->val == target){
            ListNode* delNode = head;
            head = head->next;
            //head->prev = NULL;/*head->prev = NULL before checking if head is NULL*/
            if(head != NULL)head->prev =NULL;
            delete delNode;
        }
        if(head == NULL)return head;//if only target element exists in list
            ListNode* back = head->prev;
            ListNode* temp = head;
            ListNode* front = head->next;
            while(temp != NULL){//if front != NULL then checking last node will be skipped 
                if(temp->val == target){
                    back->next = front;
                    ListNode*delNode = temp;
                    delete delNode;
                    if(front == NULL){/*temp becomes a dangling pointer after deletion
Here: ListNode* delNode = temp; delete delNode;*/
                        break;
                    }
                    temp = front;
                    front->prev = back;
                    front = front->next;
                }
                else{
                    back = temp;
                    temp = front;
                    if(front != NULL) front = front->next;
                    
                    
                }
            }
            return head;
    }
};