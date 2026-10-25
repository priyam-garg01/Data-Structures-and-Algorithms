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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL){
            return  head;
        }
        // BETTER APPROACH: POINTER REVERSAL
        ListNode* evenHead = head->next;
        ListNode* odd = head;
        ListNode* even = head->next;
        while(even != NULL && even->next != NULL){//Becz if even hasnot reached the end then odd also hasnt reaches becz even is bound to be in front of odd so only even conditions for loop
            
            odd->next = odd->next->next;
            odd = odd->next;
        
            
            even->next = even->next->next;
            even = even->next;
            
        }
        odd->next = evenHead;
        return head;
    }
};
/*T.C. = O(N/2)xxxxx
T.C. = O(N/2)*2 = T.C. = O(N){As we perform two unit operations: first next = next ka next then second:  uska next = odd itself */