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

        TreeNode* left = NULL;
        TreeNode* right = NULL;

        if(p->val <= node->val || q->val <= node->val){
            left = getCommonAncestor(node->left, p, q);
        }
        if(q->val >= node->val || p->val >= node->val){
            right = getCommonAncestor(node->right, p, q);
        }

        if(left == NULL)return right;

        else if(right == NULL)return left;
//else if both are not null
        return node;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* Lca = getCommonAncestor(root, p, q);

    return Lca;
    }
};/*BETTER APPROACH: Using the comparisons
T.C. = O(H) = O(LOGN), S.C. = O(H)*/