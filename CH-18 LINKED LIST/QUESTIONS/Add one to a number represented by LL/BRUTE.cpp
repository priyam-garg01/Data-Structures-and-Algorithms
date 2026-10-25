/*
Given the head of a singly linked list representing a positive integer number. 
Each node of the linked list represents a digit of the number, with the 1st node containing the leftmost digit of the 
number and so on. The task is to add one to the value represented by the linked list and return the head of a linked 
list containing the final value.
The number will contain no leading zeroes except when the value represented is zero itself.
*/
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
ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* newHead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        // head = newHead;
        return newHead;
    }
    ListNode *addOne(ListNode *head) {
        ListNode* temp = head;
        /*No need of this loop as we already reach last using reverse function
        while(temp->next != NULL){
            temp = temp->next;
    }
        if(temp->val < 9){
            temp->val++;
            return head;
        }
        */
        ListNode* reverseHead = reverse(head);
        temp = reverseHead;
        int sum = temp->val+1;
        int carry = sum/10;
        temp->val = sum%10;
        temp = temp->next;
        ListNode*prev = NULL;//To retain the prev of temp to add a new new Node
        while(temp != NULL && carry){//&& carry is added for breaking the loop if carry is 0
            //if(temp->val <= 9){//no need for this 
            sum = (temp->val) + carry;
            temp->val = sum%10;
            carry = sum/10;
            //}
            prev = temp;
            temp = temp->next;
        }
        /* 
        we can also use this inside loop
        if(carry && temp->next == NULL){
        temp->next = new ListNode(0);
    }
    */
        if(carry){
            ListNode* newNode = new ListNode(carry);
            prev->next = newNode;
            prev = prev;/*if(carry){
    ListNode* newNode = new ListNode(carry);
    temp->next = newNode;   // ❌ temp is NULL
}*/
        }
        ListNode* newHead = reverse(reverseHead);
        return newHead;
    }
};
//T.C.=O(3N)