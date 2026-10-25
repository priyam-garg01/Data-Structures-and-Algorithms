/*Given the head of a linked list, return the list after sorting it in ascending order.
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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* temp = head;
        //brute: store the data in an array and convert it into LL
        vector<int> v;
        while(temp != NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        //sort the arr
        sort(v.begin(), v.end());

        //convert into LL
        temp = head;
        for(int i = 0; i < v.size(); i++){
            temp->val = v[i];
            temp = temp->next;
        }
        return head;
    }
};/*//brute: store the data in an array and convert it into LL given in problem
T.C. = O(NLOGN), S.C. = O(N)*/