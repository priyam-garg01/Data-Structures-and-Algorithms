/*Given root of binary tree, return the Inorder traversal of the binary tree.
Morris Inorder Traversal is a tree traversal algorithm aiming to achieve a space complexity of O(1) 
without recursion or an external data structure.
Example 1

Input : root = [1, 4, null, 4, 2]

Output : [4, 4, 2, 1]


Example 2

Input : root = [1, null, 2, 3]

Output : [1, 3, 2]
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
    vector<int> getInorder(TreeNode* root) {
    	vector<int> inorder;
        TreeNode* curr = root;
        while(curr){
            if(curr->left == NULL){
                inorder.push_back(curr->data);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    inorder.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};
/*Start at curr (the root).
1)If there is no left child:
    Visit/print curr.
    Move to the right child (curr = curr->right).
2)If there is a left child:
    Find the predecessor (the rightmost node in curr's left subtree).
    If its right pointer is null: Point it to curr (create the temporary thread) and move 
    left (curr = curr->left).

3)If its right pointer already points to curr: Cut the thread (set it back to null), visit curr, and move 
    right (curr = curr->right).
    Repeat until curr becomes null.

That's literally the whole loop! It just uses the tree's own empty right pointers to remember the 
way back up, saving us from needing any extra memory.*/


/*Step 1: The "Two-Visit" Rule for Predecessors
The extra work in Morris Traversal comes from finding the predecessor of nodes that have a left child.

For any node with a left child, we traverse down to its predecessor exactly twice:

The first time: To find the predecessor and build the thread (link).
The second time: To find the predecessor again and destroy the thread.
Since we only do this search twice per left-child node, we aren't doing infinite work.
T.C. = O(2N){As we travel a node max of 2 times}, S.C. = O(1)*/