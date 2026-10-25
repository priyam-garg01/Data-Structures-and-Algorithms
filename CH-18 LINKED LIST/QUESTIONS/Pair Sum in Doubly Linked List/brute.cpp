/*
Given a sorted doubly linked list of positive distinct elements, 
the task is to find pairs in a doubly-linked 
list whose sum is equal to given value target.
*/
/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int, int>> vec;
        Node* temp1 = head;
        Node* temp2;
        while(temp1 != NULL){
            temp2 = temp1->next;
            while(temp2 != NULL && temp1->dat + temp2->data <= target){
                if(temp1->data + temp2->data == target){
                    vec.push_back({temp1->data, temp2->data});
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return vec;
       
    }
};
// T.C. = O(N^2)




/*Another brute with one while loop*/
/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        if(head == NULL || head->next == NULL){
            return {};
        }
        vector<pair<int, int>> vec;
        Node* temp1 = head;
        Node* temp2 = temp1->next;
        while(temp1 != NULL){
            
            if (temp2 == NULL) {
    temp1 = temp1->next;
    if (temp1 == NULL)
        break;
    temp2 = temp1->next;
}
            /*NOT CORRECT runs to second if where sum is smaller and moves to next still when both are null
            if(temp2 == NULL){
                temp1 = temp1->next;
                if(temp1 != NULL)temp2 = temp1->next;
            }
            */
            if(temp1->data + temp2->data == target){
                vec.push_back({temp1->data, temp2->data});
                temp1 = temp1->next;
                if(temp1 != NULL)temp2 = temp1->next;
            }
            else if(temp1->data + temp2->data > target){
                temp1 = temp1->next;
                if(temp1 != NULL)temp2 = temp1->next;
            }
            else
                temp2 = temp2->next;
        }
        return vec;
       
    }
};