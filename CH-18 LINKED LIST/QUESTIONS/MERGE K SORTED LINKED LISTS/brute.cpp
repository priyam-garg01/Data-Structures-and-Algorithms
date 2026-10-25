/*You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.*/
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //brute force: we can extract the data from the vector of linked lists sort it, and convert it into another linked list
        vector<int> v;
        for(int i = 0; i < lists.size(); i++){
            ListNode* temp = lists[i];
            while(temp != NULL){
                v.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(v.begin(), v.end());
        ListNode* dummyNode = new ListNode(-1);
        ListNode* newHead = dummyNode;
        for(int i = 0; i < v.size(); i++){
            newHead->next = new ListNode(v[i]);
            newHead = newHead->next;
        }
        return dummyNode->next;
    }
};
/*
//brute force: we can extract the data from the vector of linked lists sort it, and convert it into another linked list
 P = N*M where n is k that is total number of linked lists and m is number of elements in that
T.C. = O(P) + O(P) + PLOGP  == O(PLOGP + 2P)
S.C. = O(P)*/