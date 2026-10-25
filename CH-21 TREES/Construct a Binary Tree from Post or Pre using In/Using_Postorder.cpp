/*Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and 
postorder is the postorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: inorder = [-1], postorder = [-1]
Output: [-1]
 
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
    TreeNode* buildPostIn(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& mpp){
        if(postStart > postEnd || inStart > inEnd)return NULL;//Base case
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
        //The value of the root will be the last value in postorder vector
    
        
        int inRoot = mpp[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildPostIn(postorder, postStart, /*postEnd - 1,*/postStart + numsLeft - 1, inorder, inStart, inRoot - 1, mpp);
        //Here in postEnd since we are following root right left we only take the front index elements numsleft

        root->right = buildPostIn(postorder, postStart + numsLeft, postEnd - 1, inorder, inRoot + 1, inEnd, mpp);


        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < inorder.size(); i++){
            mpp[inorder[i]] = i;
        }
TreeNode* root = buildPostIn(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, mpp);
    return root;
    }
};/*Just statements ko her pher karne se runtime error aa jata hai, so thoda sa dry run karte waqt dekho ki statements ki placement kaise honi chahiye
T.C. = O(2N), S.C. = O(N)*///same as prev