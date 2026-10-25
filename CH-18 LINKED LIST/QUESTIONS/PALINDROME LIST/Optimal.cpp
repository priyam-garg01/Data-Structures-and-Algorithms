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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }
        ListNode* temp = head;

// We can apply the logic of reverse a LL on next of the middle element(in even) while next to next(in odd) and keep the first half as it is

//Finding length of linked list
int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    temp = head;
    int cnt = len/2;
    
    while(cnt){
        cnt--;
        
        temp = temp->next;
    }
    if(len%2 == 1){
        temp = temp->next;//to bypass the odd one 
       
    }
    // Now our temp points to the middle plus one node. Now reverse from here;
    ListNode* prev1 = NULL;
    ListNode* front = temp->next;
    while(front != NULL){
        temp->next = prev1;
        prev1 = temp;
        temp = front;
        front = front->next;
    } 
    temp->next = prev1;
    //Our temp now is partially a new list containing the 2nd half in a backwards fashion
    front = head;cnt = len/2;
    while(cnt){
        if(front->val != temp->val){
            return false;
        }
        front = front->next;
        temp = temp->next;
        cnt--;
    }
    return true;

    }
        
};/*Just handle the connection to middle node when the length is odd and set the prev of the list to be reversed to NULL
and make the reversed list back to OG list imp for interviews
T.C. = O(5N/2) and a 3N if list is brought back to its og
*/