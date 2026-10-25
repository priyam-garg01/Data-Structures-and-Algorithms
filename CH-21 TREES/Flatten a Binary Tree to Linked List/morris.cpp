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

    void flatten(TreeNode* root) {
    if(!root)return;

    TreeNode* curr = root;
    while(curr){
        if(curr->left != NULL){
            TreeNode* prev = curr->left;
            while(prev->right){
                prev = prev->right;//we get to the rightmost node in the left subtree
            }
                prev->right = curr->right;//Connect it to the right of curr and
                curr->right = curr->left;//change the left to link to right of curr 
                //Remember to set the left ptrs to NULL
                curr->left = NULL;
            }
        curr = curr->right;
        } 
    }
};/*MORRIS traversal:
Travel to the righmost in the left subtree and change its right to the right of curr change the right of curr to its left and make the left NULL only if the left node is not NULL otherwise just keep skipping to curr ka right
T.C. = O(2N), S.C. = O(1)*/