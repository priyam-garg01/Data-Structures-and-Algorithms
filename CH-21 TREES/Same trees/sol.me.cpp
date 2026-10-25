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

    bool treeTrav(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL)return true;

        if (p == NULL || q == NULL)
            return false;
            //if any of the one is null
            
        if(p->val != q->val)return false;
        //p != q compares memory addresses (pointers), not whether the two nodes have the same value.

        bool left = treeTrav(p->left, q->left);
        bool right = treeTrav(p->right, q->right);

        if(!left || !right)return false;

        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return treeTrav(p, q);
    }
};/*T.C. = O(N), S.C. = O(N)
Check the base cases carefully spaecially if one of them is null*/