/*You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

 

Example 1:


Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
Example 2:


Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.*/
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

    vector<int> inorder(TreeNode* node){
        vector<int> in;
        TreeNode* curr = node;
        while(curr){
            if(curr->left == NULL){
                in.push_back(curr->val);
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
                    in.push_back(curr->val);
                    curr = curr->right;
                }
            }
        } 
        return in;
    }
    void recoverTree(TreeNode* root) {
        if(!root)return;
        
        vector<int> in = inorder(root);
        //This vector will be an unsorted version of the faulted bst
        sort(in.begin(), in.end());

        //Now in is our sorted correct order of bst and by doing an inorder traversal again to match the values and updating if different using morris traversal
        int i = 0;
        TreeNode* curr = root;
        while(i < in.size()){
            if(curr->left == NULL){
            if(curr->val != in[i])curr->val = in[i];
               i++;
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
                    if(curr->val != in[i])curr->val = in[i];
                    i++;
                    curr = curr->right;
                }
            }
            // i++;
            // We should only increment i when we actually "visit" a node. This happens in only two places:
        } 
        return;
    }
};/*BRUTE:
Using inorder traversal first to check the faulted bst and then sort it and match it again via inorder traversal
T.C. = O(N) + O(NLOGN) + O(N), S.C. = O(N)*/