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

    void correctBst(TreeNode* node){
        TreeNode* curr = node;
        TreeNode* first = NULL;
        TreeNode* middle = NULL;
        TreeNode* last = NULL;
        TreeNode* before = NULL;
        while(curr){
            if(curr->left == NULL){
                if(before && before->val > curr->val){
                    if(first == NULL){
                        first = before;
                        middle = curr;
                    }
                    else{
                        last = curr;
                    }
                }
                before = curr;
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
                    if(before && before->val > curr->val){
                    if(first == NULL){
                        first = before;
                        middle = curr;
                    }
                    else{
                        last = curr;
                    }
                }
                    before = curr;
                    curr = curr->right;
                }
            } 
        } 
        //swapping will be done at last 
        /*If we swap the values while we are still traversing, we actually change the tree's values mid-run.

This causes two main issues:

It breaks the comparison logic: Once you swap a value, the next nodes you visit will be compared against the new swapped value of before, not the original one. This can completely throw off your detection of the second misplaced node.
We don't know if we need middle or last yet:
If the two swapped nodes are next to each other (like 1 and 2 in 1, 3, 2, 4), we only find one violation, and we need to swap first and middle.*/

        if(first && last)swap(last->val, first->val);
        else if(first && middle)swap(first->val, middle->val);
    }
    void recoverTree(TreeNode* root) {
        if(!root)return;
        
        correctBst(root);
        return;
    }
};/*Using the morris traversal and initiating the first, middle and last node to that where the fault points are present
T.C. = O(N), S.C. = O(1)*/