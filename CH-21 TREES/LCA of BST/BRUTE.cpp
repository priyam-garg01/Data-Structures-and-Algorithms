/*Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    TreeNode* getCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q){
        if(!node || node == p || node == q)return node;

        TreeNode* left = getCommonAncestor(node->left, p, q);

        TreeNode* right = getCommonAncestor(node->right, p, q);

        if(left == NULL)return right;

        else if(right == NULL)return left;
//else if both are null
        return node;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* Lca = getCommonAncestor(root, p, q);

    return Lca;
    }
};/*Brute force:
Similar to a simple binary tree
T.C. = O(N), S.C. = O(N)*/