/*Given root of binary tree, return the preorder traversal of the binary tree.

Morris preorder Traversal is a tree traversal algorithm aiming to achieve a space complexity of O(1) 
without recursion or an external data structure.


Example 1

Input : root = [1, 4, null, 4 2]

Output : [1, 4, 4, 2]


Example 2

Input : root = [1]

Output : [1]

Explanation : Only root node is present.*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
	public:
		vector<int> preorder(TreeNode* root){
	       vector<int> preorder;
           TreeNode* curr = root;

           while(curr){
            if(curr->left == NULL){
                preorder.push_back(curr->data);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right = curr;
                    preorder.push_back(curr->data);
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
           }
           return preorder;
		}
};