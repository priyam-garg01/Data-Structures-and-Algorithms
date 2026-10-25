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
        Node* left = head;
        Node* right = head;
        
        while(right->next != NULL){
            right = right->next;
        }
        //now right is the last node and left is the first node
        /*If sum gets larger we will move right pointer else move left pointer*/
        while(left->data < right->data){
            if(left->data + right->data == target){
                vec.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
            else if(left->data + right->data > target){
            right = right->prev;
            }
            else left = left->next;
        }
        return vec;
       
    }
};
/*T.C. = O(2N)*/