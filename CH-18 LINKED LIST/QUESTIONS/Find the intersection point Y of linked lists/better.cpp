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
       int n1 = 0; int n2 = 0;
        // intersection will be in a y position means once intersected they doesnt disjoin
        while(tempA != NULL){
            n1++;
            tempA = tempA->next;
        }
        while(tempB != NULL){
            n2++;
            tempB= tempB->next;
        }
        //We get the length of the linked lists, now if they are equal run loop from the starts of both else we move the shorter list to next untill it reaches the length same as that of another list
        tempA = headA;
        tempB = headB;

        if(n1 > n2){
            while(n1 != n2){
                tempA = tempA->next;
                n1--;
            }
        }
        else if(n2>n1){
            while(n1 != n2){
                tempB = tempB->next;
                n2--;
            }
        }
        //Now both lists temp have the same length till end
        while(n1){//or loop condition can be while tempA != tempB
            if(tempA == tempB){
                return tempA;
            }
            n1--;
            tempA = tempA->next;
            tempB = tempB->next;
        }
    return NULL;
    }
};
// T.C. = O(N1+N2 + MAX(N1, N2)), S.C. = O(1)