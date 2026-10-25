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

    TreeNode* buildBstPre(vector<int>& pre, int& i, int max){
        if(i == pre.size() || pre[i] > max)return NULL;

        TreeNode* root = new TreeNode(pre[i++]);
        
        root->left = buildBstPre(pre, i, root->val);
    
        root->right = buildBstPre(pre, i, max);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(!preorder.size())return NULL;

        int i = 0;
        TreeNode* root = buildBstPre(preorder, i, INT_MAX);
        return root;

    }
};/*OPTIMAL:
Using the preorder traversal applying the same logic as in validating the binary tree, i.e., creating an upper bound and lower bound {automatically created by observing the previous node's value}
Includes termination condition if the index equates to size and if the element is greater than bound
T.C. = O(3N) {As a node can be travelled max of 3 times for itself, returning from left subtree, right subtree}
S.C. = O(N) {Recursion stack space}

Better approach includes first sorting the preorder to get inorder and apply construct using preorder and inorder
T.C. = O(N log N) + O(N), S.C. = O(N)
*/