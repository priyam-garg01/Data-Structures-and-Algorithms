/*Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys strictly less than the node's key.
The right subtree of a node contains only nodes with keys strictly greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1*/
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

    bool checkValidBst(TreeNode* root, long maxL, long minR){
        if(!root)return true;
        if(!(root->val > maxL) || !(root->val < minR))return false;

        bool left = checkValidBst(root->left, maxL, root->val);

        bool right = checkValidBst(root->right, root->val, minR);

        if(left && right)return true;
        return false;

    }
    bool isValidBST(TreeNode* root) {
        if(!root)return true;

    long maxL = LONG_MIN;
    long minR = LONG_MAX;

        return checkValidBst(root, maxL, minR);
    }
};/*A valid binary search tree has two requirements:
For every node the max of its left subtree should be less than the node
And the min of right subtree is less than the node

Note: take long min and long max as node val may be less than int min or greater than int max
Taking ranges in the recursion as arguments
T.C. = O(N), S.C. = O(N)*/