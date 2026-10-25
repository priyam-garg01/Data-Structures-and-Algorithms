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
    // if(!node)return NULL;//Incomplete base case
    if(!node ||node == p || node == q){
        return node;
    }
    TreeNode* left = getCommonAncestor(node->left, p, q);

    TreeNode* right = getCommonAncestor(node->right, p, q);

    // if(left && !right)return left;
    // else if(!left && right)return right;
    // Refined form
    // else if(left && right){
    //     return node;
    // }
    // if(node == q || node == p)return node;
    if(left == NULL){
        return right;
    }
    else if(right == NULL){
        return left;
    }
    else{//both left and right aren't NULL
        return node;
    }
    
}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return NULL;
        TreeNode* ans = getCommonAncestor(root, p, q);
        return ans;
    }
};/*Optimal approach:
T.C. = O(N), S.C. = O(N)(Skew tree) {Recursive stack space}*/