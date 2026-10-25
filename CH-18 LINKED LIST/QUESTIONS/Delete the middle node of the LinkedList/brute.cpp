/*
You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ 
denotes the largest integer less than or equal to x.
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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        //check the length of linked list and then travel to middle and remove
        int len = 0;
        ListNode* temp = head;
        ListNode* prev = head;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        temp = head;
        int cnt = len/2;

        while(cnt){
            prev = temp;//got the prev of middle node
            temp = temp->next;//got the middle node
            cnt--;
        }
        prev->next = temp->next;
        delete temp;
        return head;
    }
};
/*Brute force: find the len, go to mid, and delete it
T.C. = O(3N/2)*/