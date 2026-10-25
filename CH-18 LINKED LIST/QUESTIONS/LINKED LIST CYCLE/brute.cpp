/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return false;
        }
//Store the presence of nodes in a map
    unordered_map <ListNode*, int> mpp;
    ListNode* temp = head;
    while(temp != NULL){
            if(mpp.find(temp) != mpp.end()){//My mistake i did mpp.find(mpp[temp]) but we have to find the object temp not mpp[temp];
                return true;
            }
            mpp[temp] = 1;
            temp = temp->next;//forgot to do this
        }
        return false;
    }
};
/*
BRUTE FORCE: STORE THE NODE AND ITS PRESENCE IN A MAP
T.C. = O(N*2LOGN){As two map functions are used mpp[temp] and find, S.C. = O(N)*/