/*
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together 
the nodes of the first two lists.
Return the head of the merged linked list.
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL){
            return list2;
        }
        else if(list2 == NULL){
            return list1;
        }
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        vector<int> v;

        while(temp1 != NULL){//n1
            v.push_back(temp1->val);
            temp1 = temp1->next;
        }
        while(temp2 != NULL){//n2
            v.push_back(temp2->val);
            temp2 = temp2->next;
        }
        sort(v.begin(), v.end());//nlogn

        //Convert arr to linked list;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* newList = dummyNode;
        ListNode* temp = newList;

        for(int i = 0; i < v.size(); i++){
            ListNode* newNode = new ListNode(v[i]);
            temp->next = newNode;
            temp = newNode;
        }
        return dummyNode->next;

    }
};/*
BRUTE FORCE: take two lists in an array sort it, and convert it into a new list
T.C. = O(2*(N1 + N2) + NLOGN)*/