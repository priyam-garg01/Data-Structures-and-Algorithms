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

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = root;
    while(node){
        int curr = node->val;
        if(curr > p->val && curr > q->val){
            node = node->left;
        }
        else if(curr < p->val && curr < q->val){
            node = node->right;
        }
        else{//If one is greater and other is smaller then node is the ans itself
            break;
        }
    }

    return node;
    }
};/*OPTIMAL: Using comparisons if both are greater and if both are smaller and, finally, if one is smaller and the other is greater
T.C. = O(H), S.C. = O(1)*/