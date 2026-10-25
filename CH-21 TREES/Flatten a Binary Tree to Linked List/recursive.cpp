/*Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 

Example 1:


Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0]
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* prev = NULL; 
    void flattenBt(TreeNode* node){
        if(node == NULL)return;

        flattenBt(node->right);
        flattenBt(node->left);
        node->right = prev;
        node->left = NULL;
        prev = node;
    
    return;
    }
    void flatten(TreeNode* root) {
        //Either we can do a preorder traversal make new nodes and chain them or direct by changing links

    if(!root)return;

        flattenBt(root);
    }
};/*First, approaching the rightmost element and changing its left node to null and right to prev where prev denotes the lastmost element in the linked list actually righmost in the linked list
T.C. = O(N), S.C. = O(N)*/