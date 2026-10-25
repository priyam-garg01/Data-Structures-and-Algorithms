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

    int findHt(TreeNode* root){
        if(root == NULL)return 0;

        int Lh = findHt(root->left);
        int Rh = findHt(root->right);

        return max(Lh, Rh) + 1;
    }

    int diameter(TreeNode* root, int &maxi){
        if(root == NULL)return 0;

        int left = diameter(root->left, maxi);
        int right = diameter(root->right, maxi);
        
        maxi = max(maxi, left + right);
        return 1 + max(left, right);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)return 0;
        int maxi = 0;//passed by refernce
        diameter(root, maxi);
        return maxi;
    }
};/*OPTIMAL: To replace the additional time complexity of finding the height, change the diameter function to return the height and not diameter while still passing the ans variable by reference and applying the logic for finding height we get the diameter in optimum time
T.C. = O(N). S.C. = O(1)*/