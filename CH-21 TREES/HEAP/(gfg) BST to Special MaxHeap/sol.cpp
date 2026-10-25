/*Given a Binary Search Tree, convert it into a Special Max Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied on all the nodes in the so converted Max Heap.

Examples:

Input: root[] = [4, 2, 6, 1, 3, 5, 7]

Output: [1, 2, 3, 4, 5, 6, 7] 
Explanation: The given BST has been transformed into a Special Max Heap while keeping the tree structure unchanged, and its postorder traversal is 1 2 3 4 5 6 7.
The converted tree is:

Input: root[] = [5, 3, 8, 2, 4, 7, 9]

Output: [2, 3, 4, 5, 7, 8, 9]
Explanation: The given BST has been transformed into a Special Max Heap while keeping the tree structure unchanged, and its postorder traversal is 2 3 4 5 7 8 9.
The converted tree is:

 
Constraints:

1 ≤ size of binary tree ≤ 105*/
/* Binary Tree Node Structure
class Node {
    public:
        int data;
        Node* left;
        Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/


class Solution {
  public:
    void inorder(Node* tree, vector<int>& ans){
        if(tree == NULL)return;
        
        inorder(tree->left, ans);
        ans.push_back(tree->data);
        inorder(tree->right, ans);
        
    }
    void postorder(Node* tree, vector<int> ans, int &i){
        if(tree == NULL)return;
        
        postorder(tree->left, ans, i);
        postorder(tree->right, ans, i);
        tree->data = ans[i++];
    }
    void convertToMaxHeap(Node* root) {
        
            /*We know that inorder traversal of BST gives us a sorted array of elements
            and if we do a postorder traversal(left->right->root) of the resultant 
            tree we get our binary search tree
            
            First we find the inorder traversal and store it in the array and then we fill 
            the elements in the existing tree by changing data as in our stored array doing
            a postorder traversal
            
            Note: There is no req for having a complete binary tree so we only change the 
            given tree as said in problem
            */
            
            vector<int> inord;//O(N)
            inorder(root, inord);//O(N)
           
            int i = 0; 
            postorder(root, inord, i);//O(N)
        
    }
};
