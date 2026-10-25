/* 
Given the head of a singly linked list consisting of only 0, 1 or 2.
Sort the given linked list and return the head of the modified list.
Do it in-place by changing the links between the nodes without creating new nodes.
*/
/*
Definition of singly linked list:
class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};
*/

//DATA REPLACEMENT
class Solution {
    public:
        ListNode* sortList(ListNode* &head) {
            ListNode* temp = head;
            int cnt0 = 0;
            int cnt1 = 0; int cnt2 = 0;
            while(temp != NULL){
                if(temp->data == 0){
                    cnt0++;
                }
                else if(temp->data == 1){
                    cnt1++;
                }
                else cnt2++;
                temp = temp->next;
            }
            temp = head;
            while(temp != NULL){
                if(cnt0 != 0){
                temp->data = 0;
                cnt0--;
                }
                else if(cnt1 != 0){
                    temp->data = 1;
                    cnt1--;
                }
                else if(cnt2 != 0)
                {
                    temp->data = 2;
                    cnt2--;
                }
                temp = temp->next;
            }
            return head;
        }
};
// T.C. = O(2N)