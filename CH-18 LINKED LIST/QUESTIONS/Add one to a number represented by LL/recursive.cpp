/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
int addOneRec(ListNode* head){//this function only aims to change the data
    int carry;
        if(head == NULL){//recursive approach requires to go till the end
           return 1;
            }
        
        head->val += addOneRec(head->next);
        if(head->val > 9){
            head->val %= 10;
            return 1;
        }
        return 0;
}
    
    ListNode *addOne(ListNode *head) {
        
        int carry = addOneRec(head);
        if(carry){
            ListNode* newNode = new ListNode(carry, head);
            head = newNode;
        }
        return head;
        
    }
};
/*T.C. = O(N), S.C. = O(N){SYSTEM STACK}*/