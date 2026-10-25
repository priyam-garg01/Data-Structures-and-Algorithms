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
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head->next == NULL)return head;
        
        ListNode* temp = head;
        //idea of knowing the len in n/2 t.c.
        int len = 1;
        while(temp != NULL && temp->next != NULL){
                temp = temp->next->next;
                len += 2;
        }
        //correct len is obtained for odd node but for even we have to decrease 1 when temp = null
        if(temp == NULL){
            len -= 1;
        }
        //Now we traverse the list in n/2 to find middle elem
        int cnt = len/2;
        temp = head;
        while(cnt){
            temp = temp->next;
            cnt--;
        }
        return temp;
    }
};
/*BETTER APPROACH: first calc len by traversing double times(jumping two times)
and then if len is even dry run for reqd adjustments
T.C. = O(N)WRONG!!{not wrong}


T.C. =O(3N/2) for using next->next
{This is only in the case we count the nodes traversed fast->2*n/2 == N
Like this Time complexity should be 3n/2}
*/