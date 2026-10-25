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
/*OPTIMAL: Use slow and fast pointers
T.C. = O(N/2){CORRECT }

 wrong since we use 2 jumps(next->next)
{This is only in the case we count the nodes traversed fast->2*n/2 and slow->n/2
==  3N/2}
*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head->next == NULL)return head;
        
        // using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        //Slow travels nodes one by one while fast travels twice of slow and our ans will be slow pointer as it stands at the middle node
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //For odd slow stops at mid and fast at the last node
        //For even slow stops at the second middle and fast at null

        return slow;
    }
};