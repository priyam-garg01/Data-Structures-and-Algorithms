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
ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* newHead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        // head = newHead;
        return newHead;
    }
    ListNode* reverseList(ListNode* head) {
       head = reverse(head);
       return head;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }
ListNode* front = head;

// We can apply the logic of reverse a LL on next of the middle element(in even) while next to next(in odd) and keep the first half as it is
//Using slow ad fast pointers
// While fast reaches the end slow points to the middle node of the list
ListNode* slow = head;
ListNode* fast = head;
while(fast->next != NULL && fast->next->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
}
//odd length slow points to the middle node
//even length slow points to the middle + 1 node
//Either way we have to reverse from slow->next part

ListNode* newHead = reverse(slow->next);
ListNode* back = newHead;
while(back != NULL){
    if(front->val != back->val){
        return false;
        }
    back = back->next;
    front = front->next;
    }
    newHead = reverse(slow->next);
    return true;
    }

};//Using slow and fast pointers