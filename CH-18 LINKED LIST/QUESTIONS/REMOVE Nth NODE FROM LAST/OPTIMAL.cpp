/*Two pointer approach making fast first point at to (n+1)th node from begining then pointing the slow to 
head and running loop till fast->next is null we will get the slow pointer behind the node to be reversed and add additional 
case if n = length of list 
*/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL){
            if(n == 1 && head != NULL){
                //To delete head
                delete head;
            }
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = NULL;
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }
        slow = head;
        if(fast == NULL){//Case to remove head
            ListNode* delNode = slow;
            //You delete the first node, but head still points to the deleted node. Returning head returns a dangling pointer.
            /*WRONG
            slow = slow->next;
            */
            head = head->next;
            delete delNode;
            return head;
        }
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        return head;
    }
};