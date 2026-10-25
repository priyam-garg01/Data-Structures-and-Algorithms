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

    int kthSmallest(TreeNode* root, int k) {
        if(!root)return -1;
        TreeNode* node = root;

    int count = 1;
    int elem = -1;
    TreeNode* curr = root;
    
    while(curr){
        if(curr->left == NULL){
            if(count++ == k){
                elem = curr->val;
                //return elem;
                //this causes some unnecessay threads to remain in the tree
                // break;
/*because you are breaking out of the loop early once you find the k-th element (which is great for efficiency!), some of the temporary threads (prev->right = curr) might still be left in the tree*/
            }
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
                if(count++ == k){
                    elem = curr->val;
                }
                curr = curr->right;
            }
        }
        
    }
    


    return elem;

    }
};/*Most optimal: In-order using Morris traversal
T.C. = O(2N), S.C. = O(1)*/