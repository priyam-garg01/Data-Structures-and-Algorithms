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

    void rightSide(TreeNode* root, map<int, int> &mpp, queue<pair<TreeNode*, int>> &q, int hz){
        if(root == NULL)return;
        q.push({root, hz});
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            if(mpp.find(hz) == mpp.end())mpp[hz] = node->val;
            rightSide(node->right, mpp, q, hz + 1);
            rightSide(node->left, mpp, q, hz + 1);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root)return ans;
//To get the right side view we only need to insert the right nodes value by first traversing to the right side and then to the left side if at that horizontal level there is no node
    map<int, int> mpp;
    queue<pair<TreeNode*, int>> q;
        rightSide(root, mpp, q, 0);
    
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};/*Recursive approach using same logic:
T.C. = O(N), S.C. = O(H)*/