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

class Solution {
    public:
        ListNode* sortList(ListNode* &head) {
        if(head == NULL || head->next == NULL){
                 return head;
            }
            ListNode* temp = head;
            //POINTER REVERSAL
            ListNode* headnew0 = new ListNode(-1);//Dummy nodes doesnt use any memory
            ListNode* headnew1 = new ListNode(-1);
            ListNode* headnew2 = new ListNode(-1);
            ListNode* ptr0 = headnew0;
            ListNode* ptr1 = headnew1;
            ListNode* ptr2 = headnew2;
            while(temp != NULL){
                if(temp->data == 0){
                    ptr0->next = temp;
                    ptr0 = temp;
                }
                else if(temp->data == 1){
                        ptr1->next = temp;
                        ptr1 = temp;
                }
                else {
                    ptr2->next = temp;
                    ptr2 = temp;
                }
                temp = temp->next;
            }
            
               
            ptr0->next = headnew1->next ? headnew1->next : headnew2->next;
            ptr1->next = headnew2->next;
            ptr2->next = NULL;

            ListNode* newHead = headnew0->next;
            delete headnew0;
            delete headnew1;
            delete headnew2;
            return newHead;
        }
};
