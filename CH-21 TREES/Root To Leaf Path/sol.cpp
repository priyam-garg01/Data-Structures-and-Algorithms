/*Given the root of a binary tree. Return all the root-to-leaf paths in the binary tree.



A leaf node of a binary tree is the node which does not have a left and right child.


Example 1

Input : root = [1, 2, 3, null, 5, null, 4]

Output : [ [1, 2, 5] , [1, 3, 4] ]

Explanation : There are only two paths from root to leaf.

From root 1 to 5 , 1 -> 2 -> 5.

From root 1 to 4 , 1 -> 3 -> 4.*/
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
        void rootToLeaf(vector<vector<int>> &ans, TreeNode* node, vector<int> &level){
        if(!node)return;
        level.push_back(node->data);

        rootToLeaf(ans, node->left, level);
        if(node->left)level.pop_back();

        rootToLeaf(ans, node->right, level);
        if(node->right)level.pop_back();

        if(node->left == NULL && node->right == NULL){
            ans.push_back(level);
        }

        }
		vector<vector<int>> allRootToLeaf(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> level;
        rootToLeaf(ans, root, level);

        return ans;
          
		}
};/*T.C. = O(N), S.C. = O(N)*/