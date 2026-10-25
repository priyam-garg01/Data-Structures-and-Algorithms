/*
Using recursion*/


/*
Definition of special linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode()
    {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2)
    {
        val = data1;
        next = next1;
        child = next1;
    }
};
*/

class Solution {
public:
    ListNode* flatten(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* newHead = flatten(head->next);
        ListNode* newList = mergeSortedList(head, newHead);
        return newList;

    }

    
    ListNode* mergeSortedList(ListNode* t1, ListNode* t2){//T.C. = O(N1 + N2)
       
    ListNode* dummyNode = new ListNode(-1);
    ListNode* res = dummyNode;
    t1->next = NULL; t2->next = NULL;
        while(t1 != NULL && t2 != NULL){
            if(t1->val > t2->val){
                res->child = t2;
                res = t2;
                t2 = t2->child;
            }
            else{
                res->child = t1;
                res = t1;
                t1 = t1->child;
            }
        }
            while(t1){
                res->child = t1;
                res = t1;
                t1 = t1->child;
            }
            while(t2){
                res->child = t2;
                res = t2;
                t2 = t2->child;
            }
            res->child = NULL;
            return dummyNode->child;
    }
    ListNode* flattenLinkedList(ListNode* &head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* temp = head;
        return flatten(temp);
        
    }
};/*using recursion we can divide the horizontal LL into separate child LL and merge then to form a single 
child list through backtracking
base condition: if next is null return head;
note to initiate the individual linked list next to null while merging
M = number of horizontal nodes while  N =  is number of vertical nodes in each child list
T.C. = O(M * MERGE) = O(M*(2N))
T.C. = O(M*N), S.C. = O(M)//Stack space in recursion
*/
