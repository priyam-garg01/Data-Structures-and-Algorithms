/*Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL){
            return  head;
        }
        // BRUTE FORCE: DATA REPLACEMENT
       //Store odd index values first and then even index values
       ListNode* dummyNode = new ListNode(-1);
       ListNode* curr = dummyNode;
       
       while(temp != NULL){
           ListNode* newNode = new ListNode(temp->val);
           curr->next = newNode;
           curr = newNode;
                if(temp->next == NULL)break;
            temp = temp->next->next;
        }
        // Even index data stored
        
        temp = head->next;
        while(temp != NULL){
            ListNode* newNode = new ListNode(temp->val);
            curr->next = newNode;
            curr = newNode;
            if(temp->next == NULL)break;
            temp = temp->next->next;
        }
        return dummyNode->next;
    }
};
           // T.C. = O(N), S.C. = O(N)