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
    int findLengthOfLoop(ListNode *head) {
   
    ListNode* slow = head;
    ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast){

        int pos = 1;// notes the length of loop
        fast = fast->next;
        while(fast != slow){
            pos++;
            fast = fast->next;
                }
                return pos;
            }
        }

            return 0;
    }
};
/*
Using slow and fast pointers when they meet each other run a single loop with count determining the len of loop
T.C. = O(2N)
*/