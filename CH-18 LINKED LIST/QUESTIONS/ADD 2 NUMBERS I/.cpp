/*You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/
/*
Hint:Whenever we need to make a new list to store the ans always use dummy node 
makes it super simple in storing the answers
*/




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;
        int carry = 0;  int sum = 0;

    while(temp1 != NULL || temp2 != NULL){//We will use or operator as we can sum all the digits in one single loop only no nedd to write extra conditions for variable sizes of lists
        sum = carry;
    if(temp1 != NULL)sum += temp1->val;
    if(temp2 != NULL) sum += temp2->val;
        carry = sum/10;
        ListNode* newNode = new ListNode(sum%10);
        curr->next = newNode;
        curr = curr->next;
        
        if(temp1 != NULL)temp1 = temp1->next;//As null ka next gives null exception error
        if(temp2 != NULL)temp2 = temp2->next;
        }
        //If carry remains at last
        if(carry){
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode;
            curr = curr->next;
        }
        return dummyNode->next;//which is head of the sumlist
    }
};
// T.C. = O(max(l1, l2)), S.C. = O(max(L1, L2))