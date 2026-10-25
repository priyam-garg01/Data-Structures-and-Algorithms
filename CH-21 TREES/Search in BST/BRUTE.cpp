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

    TreeNode* bstSearch(TreeNode* node, int val){
        if(!node)return NULL;

        if(node->val == val)return node;

        else if(node->val > val){
            return bstSearch(node->left, val);
        }
        return bstSearch(node->right, val);

        
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)return NULL;

        return bstSearch(root, val);
    }
};/*Binary search in Binary Search Tree:
T.C. => O(H) = O(log n), S.C. = O(log n)*/