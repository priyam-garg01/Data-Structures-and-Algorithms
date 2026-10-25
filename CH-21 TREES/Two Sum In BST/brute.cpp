/*Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

 

Example 1:


Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Example 2:


Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105*/
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
    bool findTarget(TreeNode* root, int k) {
        vector<int> in;
        TreeNode* curr = root;

        while(curr){
            if(curr->left == NULL){
                in.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    in.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
    //Got the sorted order array for 2 sum
    int i = 0; 
    int j = in.size()-1;
    int sum = 0;
    while(i < j){
    sum = in[i] + in[j];

    if(sum == k)return true;

    else if(sum > k){
        j--;
    }
    else{
        i++;
    }

    }
       return false; 
    }
};/*BRUTE FORCE:
Find the array representation by inorder traversal and then apply same logic as in 2 sum problem
T.C. = O(N) + O(N){Moving only 1 ptr}
S.C. = O(N)*/