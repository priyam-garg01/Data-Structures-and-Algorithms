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
private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
private: 
    void inorder(TreeNode* root){
        if(!root)return;

        inorder(root->left);//Go to left

        if(prev != NULL && prev->val > root->val){
            if(first == NULL){
                first = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }
        prev = root;//Print root
        inorder(root->right);//Go to right
    }
public:
    
    void recoverTree(TreeNode* root) {
        if(!root)return;
        first = NULL;
        middle = NULL;
        last = NULL;
        prev = NULL;
        inorder(root);
        if(first && last)swap(first->val, last->val);
        else if(first && middle)swap(first->val, middle->val);
        
        return;
    }
};/*Using the recursive inorder traversal
T.C. = O(N), S.C. = O(N)*/