/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;//If there is only one node, returning head returns the original node, not a copy. so only works if head is null if one element the copy will be made and then returned
        }
        Node* temp = head;
        
//Creating new nodes in the existing list only
    //1.Inserting the nodes between the list nodes
    while(temp != NULL){
        Node* copyNode = new Node(temp->val);
        copyNode->next = temp->next;
        temp->next = copyNode;
        temp = temp->next->next;
        }

    //2.Connecting the random pointers{{{*****}}}
    temp = head;
    Node* copyNode;
    while(temp != NULL){//To get the random pointers to point to copy and not to the OG list we point it to temp ke random ka next
    copyNode = temp->next;
        if(temp->random)copyNode->random = temp->random->next;
        else copyNode->random = NULL;//imp as null ka next is not defined
        temp = temp->next->next;
        }
    //3.Removing the link between the two lists
    Node* dummyNode = new Node(-1);
    copyNode = dummyNode;
    temp = head;
    while(temp != NULL){
        copyNode->next = temp->next;
        temp->next = temp->next->next;
        copyNode = copyNode->next;
        temp = temp->next;
        }
        return dummyNode->next;
    }
};/*
Optimal:
Making new nodes within the given list, connecting the random pointers with their copies if they exist and at last separating the two lists
T.C. = O(3N), S.C. = O(N){REQD TO MAKE THE COPY}*/