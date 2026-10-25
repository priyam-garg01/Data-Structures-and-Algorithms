/*Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 

Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1*/
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

    int diameter(TreeNode* root, int maxi){
        if(root == NULL)return 0;

        int Lh = findHt(root->left);
        int Rh = findHt(root->right);

        maxi = max(maxi, Lh + Rh);

        int left = diameter(root->left, maxi);
        int right = diameter(root->right, maxi);
        if(right < left){
        maxi = max(left, maxi);
    }
    else 
    maxi = max(maxi, right);
        return maxi;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)return 0;

        return diameter(root, 0);
    }
};/*BRUTE FORCE: For every node, check its height 
T.C. = O(N^2)*/