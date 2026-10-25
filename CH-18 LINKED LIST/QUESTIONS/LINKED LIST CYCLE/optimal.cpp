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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        //Agar slow and fast pointers mile then loop occurs
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};
/*
Better using slow and fast pointers:
T.C. = O(N)
INTUITION: After fast has passed a certain node the distance between fast and slow is max, then pointers move in such a way that fast tends to move close to slow by 2 units and slow away from fast by 1 unit 
Since the max distance will always be divided by 1 slow and fast are bound to meet
*/