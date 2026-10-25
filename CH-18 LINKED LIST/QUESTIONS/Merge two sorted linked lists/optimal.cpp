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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL){
            return list2;
        }
        else if(list2 == NULL){
            return list1;
        }
        ListNode* temp1;
        ListNode* temp2;
        if(list1->val > list2->val){
            temp1 = list1;
            temp2 = list2;
        }
        else{
            temp1 = list2;
            temp2 = list1;
        }
        ListNode* prev = temp2;
        while(temp1 != NULL && temp2 != NULL){
            if(temp1->val > temp2->val){
                prev = temp2;
                temp2 = temp2->next;
            }
            else {
    ListNode* dummyNode = new ListNode(temp1->val, prev->next);
            prev->next = dummyNode;
            prev = prev->next;
            temp1 = temp1->next;
            }
        }
        //when one of the list becomes null has lesser values of elements than the other then we need to add the other lists elements, here temp1 points to that
        while(temp1 != NULL){
            prev->next = temp1;
            prev = prev->next;
            temp1 = temp1->next;
        }



        if(list1->val > list2->val){
            return list2;
        }
        else{
            return list1;
        }

    
        

    }
};/*OPTIMAL: 
use any of the two list to store and return that list using the better approach, note to store the prev when temp1 ki val is greater
T.C. = O(N)
*/
// no need of finding the list ehose first element is small

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