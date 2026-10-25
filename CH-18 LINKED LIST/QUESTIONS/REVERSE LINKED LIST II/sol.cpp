/*Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
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
    void reverse(ListNode* &head, ListNode* &tail) {
        if (head == NULL || head == tail)
            return;

        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp != NULL) {
            ListNode* nextP = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextP;
        }

        tail = head;
        head = prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || left == right)
            return head;

        ListNode* temp = head;
        ListNode* prevNode = NULL;

        int count = 1;

        // Move temp to the right-th node
        while (count < right) {
            if (count < left)
                prevNode = temp;

            temp = temp->next;
            count++;
        }

    ListNode* front = (prevNode ? prevNode->next : head);//front node exits if prevNode->next(null->next) exits as it can be null as well
    ListNode* frontTail = front;   // save original left node
    ListNode* back = temp;

    ListNode* nextNode = back->next;
    back->next = NULL;

    reverse(front, back);

    if(prevNode)
        prevNode->next = front;
    else
        head = front;

        frontTail->next = nextNode;

    return head;
    }
};//T.C. = O(2N), S.C. = O(1)