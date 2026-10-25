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

    int maxSum(TreeNode* root, int &maxS){
       if(root == NULL)return 0;

        int left = max(0, maxSum(root->left, maxS));//To exclude if the path sum is negative initiate it to zero

        int right = max(0, maxSum(root->right, maxS));//To exclude if the path sum is negative initiate it to zero

        maxS = max(maxS, left + right + root->val);

        return (root->val + max(left, right));
        
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL)return 0;

        int maxS = root->val;
        maxSum(root, maxS);

        return maxS;
    }
};