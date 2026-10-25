
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


    ListNode* merge(ListNode* t1, ListNode* t2){//T.C. = O(N1+N2)
        if(t1 == NULL){
            if(t2 == NULL){
                return NULL;
            }
            return t2;
        }
        if(t2 == NULL) return t1;

        ListNode*dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(t1 != NULL && t2 != NULL){
            if(t1->val > t2->val){
                temp->next = t2;
                temp = temp->next;
                t2 = t2->next;
            }
            else{
                temp->next = t1;
                temp = temp->next;
                t1 = t1->next;
            }
        }
        while(t1 != NULL){
                temp->next = t1;
                temp = temp->next;
                t1 = t1->next;
        }
        while(t2 != NULL){
                temp->next = t2;
                temp = temp->next;
                t2 = t2->next;
        }
        return dummyNode->next;
    }
    ListNode* mergeSortLL(ListNode*head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        // firstly divide in two halves
        ListNode* temp = head;
        int len = 0;
        while(temp != NULL){//O(N)
            temp = temp->next;
            len++;
        }
        int count = len/2;
        temp = head;
        ListNode* t1 = head;
        ListNode* t2 = head;
        while(count){//O(N/2)
            temp = t2;
            t2 = t2->next;
            count--;
        }
        //we can also use tortoise and hare algo to find mid just that initially point fast to head->next so that we get the prev mid in case of even len like
/*T.C. = O(N/2)
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //slow points to prev mid
        ListNode* t2 = slow->next;
        slow->next = NULL;
        ListNode* t1 = head;
*/
        temp->next = NULL;
        ListNode* head1 = mergeSortLL(t1);
        ListNode* head2 = mergeSortLL(t2);
        /*
        ListNode* newHead = merge(t1, t2);//head 1 and head2 should be merged
        */
        ListNode* newHead = merge(head1, head2);
        return newHead;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        //Using merge sort dividing the linked list and attacking on individual nodes
        return mergeSortLL(head);

    }
};/*T.C. = O(n/2){for finding the mid} + O(n){for merging} 
this will be multiplied by time complexity for operating recursion like in merge sort of logn
T.C. = O((3*NLOGN)/2), S.C. = O(1) No extra space used except for O(N) recursion stack space*/