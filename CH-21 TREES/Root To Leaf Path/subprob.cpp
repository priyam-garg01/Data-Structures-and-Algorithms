//Similar to root to leaf this time its root to a particular node whose value is given to us

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
        bool rootToNode(vector<int> &ans, TreeNode* node, int x){
        if(!node)return;

        level.push_back(node->data);

        if(node->data == x)
        return true;

        if(rootToNode(ans, node->left, x) || rootToNode(ans, node->right, x))
        return true;

        level.pop_back();
        return false;//If that particular node is not found

        }
		vector<vector<int>> RootToNode(TreeNode* root, int B){
        vector<int> level;
        rootToLeaf(ans, root, B);

        return ans;
          
		}
};//T.C. = O(N), S.C. = O(N) + O(N)