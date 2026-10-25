/*Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.*/
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

TreeNode* buildPreIn(vector<int>& preorder,int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> &inMap){
    if(preStart > preEnd || inStart > inEnd)return NULL;

    TreeNode* root = new TreeNode(preorder[preStart]);

    int inRoot = inMap[root->val];//Signifies the index at which the sam eval is present in the inorder vector
    int numsLeft = inRoot - inStart;//Depicts the number of nodes to the left of the current root node

    root->left = buildPreIn(preorder, preStart + 1, preEnd, inorder, inStart, inRoot - 1, inMap);

    root->right = buildPreIn(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    /*
        First as we have the root in the preorder at first we will find it in inorder traversal and set it to the root of the tree, Then we move to its right subarray of inorder and and right subarray to find the next roots by incrementing our counter in the preorder subarray
        */

        //To resist the iteration of loop each time to find the first element of the preorder
//  we set the map to locate where the consecutive roots are found in the preorder vector
        
        map<int, int> mpp;
        for(int i = 0; i < inorder.size(); i++){
            mpp[inorder[i]] = i;
        }
    TreeNode* root = buildPreIn(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mpp);

        return root;
    }
};//T.C. = O(N).logn {ordered map or O(1) for unordered map}, S.C. = O(N)