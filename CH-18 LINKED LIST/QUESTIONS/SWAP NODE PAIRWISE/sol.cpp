/*
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
Example 1:

Input: head = [1,2,3,4]

Output: [2,1,4,3]*/
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

    void swapNodes(ListNode* head){
        if(head == NULL || head->next == NULL){
            return ;
        }
        ListNode* temp = head;
        ListNode* nextNode = temp->next;
        temp->next = nextNode->next;
        nextNode->next = temp;
        
        return ;
    }
    /*This can be used as well
    ListNode* swapNodes(ListNode* head) {
    ListNode* second = head->next;
    head->next = second->next;
    second->next = head;
    return second;
}
Adding this in main function:
ListNode* newHead = swapNodes(first);

if (prev == NULL)
    head = newHead;
else
    prev->next = newHead;

prev = first;          // first is now the tail
first = first->next;   // move to next pair
*/
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        } 
        ListNode* prev = NULL;
        ListNode* first = head;
        ListNode* second = head->next;
        while(first != NULL){
            //we first need to store the next of second
            if(prev)prev->next = second;
            swapNodes(first);
            if(!prev) head = second;//This was the main mssing piece behind error
            prev = first;
            first = first->next;
            if(first == NULL || first->next == NULL)break;
            second = first->next;
        }

    return head;
    }
};
/*Swap nodes pairwise using a function by appointing the first second and prev pointers reinitialize head during first swap
T.C. = O(N), S.C. = O(1)*/