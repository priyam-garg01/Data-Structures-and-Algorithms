/*You are given the root of a binary tree, and the task is to determine whether it satisfies the properties of a max-heap.

A binary tree is considered a max-heap if it satisfies the following conditions:

Completeness: Every level of the tree, except possibly the last, is completely filled, and all nodes are as far left as possible.
Max-Heap Property: The value of each node is greater than or equal to the values of its children.*/
/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
    // bool isComplete(Node* tree){
    //     if(tree == NULL)return true;
        
    //     if(tree->right != NULL && tree->left == NULL)return false;

    //     return isComplete(tree->right) && isComplete(tree->left);
    // }
        /*Example counter-case: A tree where the root has a left child with 
        two children, and a right child with no children. Your logic 
        returns true, but if the bottom level is not filled from left to 
        right, it is not complete.As the left child child may have a child*/
    bool isComplete(Node* tree, int n, int i){
        if(tree == NULL)return true;
        if(i >= n)return false;
        
        return(isComplete(tree->left, n, 2*i + 1) && isComplete(tree->right, n, 2*i + 2));
    }
    
    bool isMaxHeap(Node* tree){
        if(tree == NULL)return true;
        
        if(tree->left && tree->left->data > tree->data)return false;
        if(tree->right && tree->right->data > tree->data)return false;
        
        bool lf = true;
        if(tree->left)lf = isMaxHeap(tree->left);
        
        bool rt = true;
        if(tree->right)rt = isMaxHeap(tree->right);
        
        return lf && rt;
    }
    
    int ctNodes(Node* tree){
        if(tree == NULL)return 0;
        
        return 1 + ctNodes(tree->left) + ctNodes(tree->right);
    }
    bool isHeap(Node* tree) {
        /*We need to check for two things:
        1)Complete or not 2)maxHeap or not
        Key Requirements for Completeness:
        A binary tree is complete if, using 0-based index representation (where parent i
has children 2*i + 1 and 2i+2):

        Every node's index is strictly less than the total node count N.
        */
        int nodes = ctNodes(tree);//O(N)
        
        if(!isComplete(tree, nodes, 0))return false;//O(N) 
        
        return isMaxHeap(tree);//O(N)
    }
};