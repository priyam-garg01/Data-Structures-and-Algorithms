/*
Given the head of a doubly linked list with its values 
sorted in non-decreasing order. Remove all duplicate occurrences of any value in the list 
so that only distinct values are present in the list.

Return the head of the modified linked list.
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
    ListNode * removeDuplicates(ListNode *head) {
//APPROACH:Visit every node and its next if they are equal remove the second node
    ListNode* temp1 = head;
    ListNode*temp2;
    while(temp1 != NULL){
        temp2 = temp1->next;
        while(temp2 != NULL){
            if(temp1->val == temp2->val){
                temp1->next = temp2->next;
                ListNode*delNode = temp2;
                if(temp2->next != NULL){
                    temp2 = temp2->next;
                    temp2->prev = temp1;
                    }
                else{
                    temp2 = NULL;//if not done then temp2 will be a dangling pointer and trapped inside the inner while loop
                }
                delete delNode;
                }
            else
                temp2 = temp2->next;
            }
            temp1 = temp1->next;    
        }
        return head;
    }
};
// to do the deletion and substitution step this could have been used:
/*
ListNode* delNode = temp2;
temp2 = temp2->next;      // Save next node first

temp1->next = temp2;
if(temp2)
    temp2->prev = temp1;

delete delNode;
*/