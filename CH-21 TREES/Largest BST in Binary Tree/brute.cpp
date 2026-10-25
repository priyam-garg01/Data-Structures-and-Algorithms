/*Given a root of Binary Tree, where the nodes have integer values. Return the size of the largest 
subtree of the binary tree which is also a BST.

Example 1
Input : root = [2, 1, 3]
Output : 3

Explanation :

The given complete binary tree is a BST consisting of 3 nodes.

Example 2
Input : root = [10, null, 20, null, 30, null, 40, null, 50]
Output : 5

Explanation :

If we consider the node 10 as root node then it forms the largest BST.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

bool validateBst(TreeNode* node, long mini, long maxi){
    if(!node)return true;

    if(node->data >= maxi || node->data <= mini)return false;

    bool left = validateBst(node->left, mini, node->data);

    bool right = validateBst(node->right, node->data, maxi);

    if(left && right)return true;

    return false;
}

int countNodes(TreeNode* node){
    if(!node)return 0;

    return 1 + countNodes(node->left) + countNodes(node->right);
}
class Solution{
	public:
		int largestBST(TreeNode* root){
			if(!root)return 0;
            if(validateBst(root, LONG_MIN, LONG_MAX)){
                return countNodes(root);
            }
            //Else return max of count nodes in left and right subtree
            return max(largestBST(root->left), largestBST(root->right));
		}
};/*Validate the binary tree node by node recursively and when validation if done count the nodes
T.C. = O(N*N), S.C. = O(N) + O(N)*/