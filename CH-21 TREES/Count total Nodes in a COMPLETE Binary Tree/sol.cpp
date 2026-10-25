/*Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

 

Example 1:


Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [1]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [0, 5 * 104].
0 <= Node.val <= 5 * 104
The tree is guaranteed to be complete.*/
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

    int findHtLeft(TreeNode* node){
        int ht = 0;
        while(node){
            ht++;
            node = node->left;
        }
        return ht;
    }
    int findHtRight(TreeNode* node){
        int ht = 0;
        while(node){
            ht++;
            node = node->right;
        }
        return ht;
    }
    int CtNodes(TreeNode* root){
        if(!root)return 0;

        int lh = findHtLeft(root);
        int rh = findHtRight(root);

        if(lh == rh)return (1<<lh) - 1;

        return 1 + CtNodes(root->left) + CtNodes(root->right);
    }

    int countNodes(TreeNode* root) {
        if(!root)return 0;
       

        int ans = CtNodes(root);
        return ans;
    }
};/* /*We will use recurdion to add up the node count using backtracking
        Our simple idea is that we will first calc the left height and right height of the tree :
        If they are found to be equal then we will return the number of node {2^lh or rh - 1}(Here we will calc height as a count of number of nodes occured to simplify the node counting)
        And if they are unequal then we use:1 + CtN(root->left) + CtNode(root->left)jisse kisi stage mai{Uncomplete stage} hame null mil jayega and returned using base case
T.C. = O(LOGN)*(LOGN) {As at max the height of the tree would be logn which we are travelling as it is a complete B.T. so we traverse at max Logn nodes and find their height whose t.c. = O(LOGN), S.C. = O(LOGN)}
        */
