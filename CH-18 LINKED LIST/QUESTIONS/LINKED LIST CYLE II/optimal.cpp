/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
           slow = slow->next;
           fast = fast->next->next;
           if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
           }
        }
        
        return NULL;
    }
};
/*
Stopping at the point where slow meets fast 1st time leaves us with 2 questions:
What if they doesn't meet again after appointing one of them to head
2nd how it is that when they meet it gives us the starting node of loop:
in notebook. T.C. = O(N)
*/