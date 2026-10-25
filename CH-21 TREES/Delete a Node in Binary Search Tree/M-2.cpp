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

    TreeNode* helper(TreeNode* node){
        if(node->left == NULL){
            return node->right;
        }
        else if(node->right == NULL){
            return node->left;
        }
        //If both left and right are there
        TreeNode* leftChild = node->left;
        TreeNode* lastLeft = findLastLeft(node->right);
        lastLeft->left = leftChild;
        return node->right;
    }
    TreeNode* findLastLeft(TreeNode* node){
        if(node == NULL || node->left == NULL)return node;

        return findLastLeft(node->left);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return NULL;
        if(root->val == key){
            return helper(root);
        }
    TreeNode* node = root;

        while(node){
            if(node->val > key){
                if(node->left != NULL && node->left->val == key){
                    node->left = helper(node->left);
                    break;
                }
                else{
                    node = node->left;
                }
            }
            else{
                if(node->right != NULL && node->right->val == key){
                    node->right = helper(node->right);
                    break;
                }
                else{
                node = node->right;
                }
            }
        }
        return root;

    }
};/*Steps:
1) Search the node one step before the loop by checking the val of node ka left or right equal to the key.
2) Then use the helper function to alter the links, especially when both left and right are present; 
use the store of the left child and travel to the leftmost child of the node ka right and connect it to that*/