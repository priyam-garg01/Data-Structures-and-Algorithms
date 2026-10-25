/*
Given the head of a singly linked list, find the length of the loop in the linked list if it exists. 
Return the length of the loop if it exists; otherwise, return 0.
A loop exists in a linked list if some node in the list can be reached again by continuously 
following the next pointer. Internally, pos is used to denote the index (0-based) of the node from where the loop starts.

Note that pos is not passed as a parameter.
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
    int findLengthOfLoop(ListNode *head) {
unordered_map <ListNode*, int> mpp;//store the node and the node number
    //If while running the loop the node comes again return the val = diff + 1;
   
   
    ListNode* temp = head;

   
    int pos = 1;// notes the length of linked list and position

        while(temp != NULL){
            if(mpp.find(temp) != mpp.end()){
                return (pos-mpp[temp]);//count = len of list + 1 at the end and subtracting the repeated node index will give the len of loop
            }
            mpp[temp] = pos++;
            temp = temp->next;
            }
            return 0;
    }
};
/*
T.C. = O(N*2LOGN), S.C. = O(N)*/