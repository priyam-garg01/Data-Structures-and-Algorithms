/*
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
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
    bool isPalindrome(ListNode* head) {
        //BRUTE FORCE: Store the values in a stack and keep checking T.C. = O(2N), S.C. = O(N)
        ListNode* temp = head;
        stack<int> st;
        while(temp != NULL){
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL){
            if(temp->val != st.top()){
                return false;
            }
            st.pop();
            temp = temp->next;
        }
        return true;

    }
};
/*BRUTE FORCE: OR Run a loop till end once and run the second loop till n/2 times
T.C. = O(3N/2), S.C. = O(N)*/