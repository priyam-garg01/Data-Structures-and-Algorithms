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
                //To delete node
                delete head;
            }
            return head;
        }
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        int lenList = count;
//To delete the nth last node == we need to change the link of its previous node to its next node
//EX: 5 nodes, to remove 4th last node == count-n = 1-->change the link of first node
if(count-n == 0){
    ListNode* delNode = head;
    head= head->next;
    delete delNode;
    return head;
}
        temp = head;int cnt = 1;
        while(cnt != count-n){
            if(temp == NULL){
                break;
            }
            temp = temp->next;
            cnt++;
        }
        //From here we get twmp positioned at a node previous than the node to be deleted
        if(temp == NULL || temp->next == NULL){
            return head;
        }
        ListNode* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
        return head;
    }
};
/*With deletion of nodes
T.C. = O(2n) in worst case otherwise
T.C. = O(N + N-n)= O(2N - n)*/