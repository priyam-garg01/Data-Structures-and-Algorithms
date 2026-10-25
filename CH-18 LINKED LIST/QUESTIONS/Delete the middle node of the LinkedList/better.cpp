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
        ListNode* temp = head;
        ListNode* prev = head;
        while(temp != NULL && temp->next != NULL){
            len += 2;
            temp = temp->next->next;
        }
        if(temp == NULL){//even length subtract one
            len -= 1;
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
};/*BETTER: use fast pointer and calc len in n/2 and in further n/2 delete the node*/