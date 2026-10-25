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

    void rightSide(TreeNode* node, vector<int> &ans, int hz){
        if(node == NULL)return;
        if(ans.size() == hz){
            ans.push_back(node->val);
        }
        rightSide(node->right, ans, hz + 1);
        rightSide(node->left, ans, hz + 1);

        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root)return ans;

        rightSide(root, ans, 0);
        return ans;
    }
};/*Optimized recursive approach:
T.C. = O(N), S.C. = O(H) + O(N){Recursive stack space}*/