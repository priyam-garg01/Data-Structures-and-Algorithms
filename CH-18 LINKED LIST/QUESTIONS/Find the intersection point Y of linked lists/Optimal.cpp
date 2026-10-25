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
/*SOLUTION:make the node of smaller list to travel the difference of distance in both lists by assigning it to its adjacent lists heads*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
       if(headA == NULL || headB == NULL){
        return NULL;
       }
        // intersection will be in a y position means once intersected they doesnt disjoin
        /*
        while traversing the linked lists with tempA and tempB till they are deemed equal
        keeping reinitialising temps to heads of their opposite linked lists when their next is found to be null

        After one iteration the temp of smaller list points to head of larger list and when temp of larger list reaches null 
        it travels back to temp of samller list
        This way both the pointers presently moves with same length ending to null
        */
        while(tempA != tempB){
            if(tempA == NULL){
                tempA = headB;
            }
            else
                tempA = tempA->next;
            if(tempB == NULL){
                tempB = headA;
            }
            else 
                tempB = tempB->next;
            
        }
        return tempA;
    }
};//T.C. = O(2*max(n1,n2) - their diff)like(2n1-n2) WRONG!!! semi-best case 
//in case of null the total iterations are n1+n2