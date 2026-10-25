/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.
Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]*/
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
    ListNode* findKthNode(ListNode* temp, int k){
        k -= 1;
        while(temp != NULL && k){
            temp = temp->next;
            k--;
        }
        return temp;
    }
    void reverse(ListNode* head){
        if(head == NULL || head->next == NULL){
            return ;
        }
        //Reversing the pointers
        ListNode* front = head->next;
        ListNode* temp = head;
        ListNode* prev = NULL;//initiated null as list len can be less than k
        while(temp != NULL){
            temp->next = prev;
            prev = temp;
            temp = front;
            if(front)front = front->next;
        }
        return;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1){
            return head;
        }
        //take count for finding the nodes make it a list and reverse the data by a function
        ListNode* temp = head;
        ListNode* kthNode;
        ListNode* prevNode = NULL;
        ListNode* nextNode;
        while(temp != NULL){
            kthNode = findKthNode(temp, k);//find the kth node
            if(kthNode == NULL){//Agar aa ge k se kam hue  toh break
                if(prevNode)prevNode->next = temp;//if prevNode not null to connect the last list
                break;
            }
            else{
                nextNode = kthNode->next;//noting the nextNode
                kthNode->next = NULL;//to gain a sub Llist
                reverse(temp);
                temp->next = nextNode;
                if(temp == head){//agar starting mai hua then newHead assign
                    head = kthNode;
                }
                else{
                    prevNode->next = kthNode;//connecting the previous LL
                }
                prevNode = temp;
                temp = nextNode;

            }
        }
            return head;
    }
};/*T.C. = O(N){for reversing if k = 1} + O(N) for finding k
T.C. = O(2N)*/