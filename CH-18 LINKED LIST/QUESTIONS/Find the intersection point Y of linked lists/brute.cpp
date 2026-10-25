/*
Find the intersection point of Y LL:The linked list intersection will form a y shape for sure
Given the heads of two linked lists A and B, containing positive integers. 
Find the node at which the two linked lists intersect. If they do intersect, 
return the node at which the intersection begins, otherwise return null.
*/

/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        unordered_map<ListNode*, int> mpp;
        // intersection node doesn't only have same data but also same next pointer that can be adjusted as int by storing val of next node
        while(tempA != NULL){//-->T.C. = O(N1*logn) or {O(N) OR O(N^2)WORST CASE IN UNORDERED MAP}
            mpp[tempA] = 1;
            tempA = tempA->next;
        }
        while(tempB != NULL){//-->T.C. = O(N2*logn) or {O(N) OR O(N^2)WORST CASE IN UNORDERED MAP}
            if(mpp.find(tempB) != mpp.end()){
                return tempB;
            }
            tempB= tempB->next;
        }
        // T.C. = O(N1 + N2) OR O(N1log(S.C.) + N2log(S.C.)), S.C. = O(min(N1, N2));
    return NULL;

    }
};