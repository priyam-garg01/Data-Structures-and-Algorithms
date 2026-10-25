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
        int len = 1;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = head;
        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        //At last slow points to the middle node
        prev->next = slow->next;
        delete slow;
        return head;
    }
};/*OPTIMAL: tortoise and hare algo
T.C. = O(N/2)*/