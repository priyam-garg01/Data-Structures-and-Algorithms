/*Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100*/
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

    bool checkSymm(TreeNode* n1, TreeNode* n2){
        if(n1 == NULL || n2 == NULL){
            return n1 == n2;//Also we have to check the nodes too and not only their values
        }
        if(n1->val != n2->val)return false;
/*This is checking only from one side that is away from the mirror who will check closer to the mirror
//         if(n1->left && n2->right){
//         bool check = checkSymm(n1->left, n2->right);
//         if(!check)return false;
//         return true;
//         }
// if((n1->left && !n2->right) || (n1->right && !n2->left) || (!n1->left && n2->right) || (!n1->right && n2->left))return false;

        else return true;
*/
return (checkSymm(n1->left, n2->right) && checkSymm(n1->right, n2->left));

        
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        //Taking the two child nodes of the root node we can do a level order traversal one staring from left another starting from right and comparing the values we find if the tree is symm or not
    if(checkSymm(root->left, root->right))return true;
    else return false;
    }
};/*Recursive traversal:
T.C. = O(N), S.C. = O(N/2) {Recursive stack space}*/