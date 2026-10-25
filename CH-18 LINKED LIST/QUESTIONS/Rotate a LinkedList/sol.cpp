/*
Given the head of a linked list, rotate the list to the right by k places.
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
       /*
        if k is one temp->next = head and temp->prev->next = NULL so we need two pointers one to temp the last node and another to second last node
       */
       /*
        while(k%len){
            temp->next = head;
            prev->next = NULL;
            head = temp;
            temp = prev;
        }
       Instead of this we can travel the node whose next will be null after rotation by len - k make the connection to head and update head
        */
        ListNode*tail = head;
        int len = 1;
        while(tail->next != NULL){
            len++;
            tail = tail->next;
        }
        // tail points to last node
        if(k%len == 0){
            return head;
        }
        tail->next = head;
        int pos = len - k%len;
        ListNode*temp = head;

        while(pos - 1){
            temp = temp->next;
            pos--;
        }
        // temp points to the updated tail;
        ListNode* newHead = temp->next;
        temp->next = NULL;
        head = newHead;

        return head;
    }
};/*
Find the length and get the tail of LL, note the node which will be pointed to null after rotations make its next to newHead and its next reinitialized to null
check for if k% len
T.C. = O(2N)
*/