/*Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
 

Example 1:


Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
Example 3:

Input: root = [], key = 0
Output: []*/
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
        TreeNode* rightChild = node->right;
        TreeNode* lastRight = findLastRight(node->left);
        lastRight->right = rightChild;
        return node->left;
    }
    TreeNode* findLastRight(TreeNode* node){
        if(node == NULL || node->right == NULL)return node;
        
        return findLastRight(node->right);
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
2) Then use the helper function to alter the links, especially when both left and right are present; use the 
store of the right child and travel to the rightmost child of the node ka left and connect it to that*/