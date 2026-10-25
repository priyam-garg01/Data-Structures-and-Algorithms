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
   
    ListNode* merge(ListNode* t1, ListNode* t2) {
    ListNode dummy(-1);
    ListNode* tail = &dummy;

    while (t1 && t2) {
        if (t1->val <= t2->val) {
            tail->next = t1;
            t1 = t1->next;
        } else {
            tail->next = t2;
            t2 = t2->next;
        }
        tail = tail->next;
    }

    tail->next = (t1 ? t1 : t2);

    return dummy.next;
}



    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // APPROACH USING RECURSION
        if(lists.size() == 0){
            return NULL;
        }
        ListNode* head = lists[0];
        for(int i = 1; i < lists.size(); i++){
            head = merge(head,lists[i]);
        }
        return head;
    }
};/*//APPROACH USING RECURSION 
N = size of each linked list, M = number of linked lists
T.C. = O(M)*O(N + 2N + 3N + 4N ...
T.C. = O(M*N*(N+1)/2) as the size of individual lists keeps on adding up 
T.C. = O(N^3)*/