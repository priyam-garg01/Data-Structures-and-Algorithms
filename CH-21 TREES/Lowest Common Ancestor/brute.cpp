/*Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getPath(vector<TreeNode*> &ans, TreeNode* node, TreeNode* x){
        if(!node)return false;

        ans.push_back(node);

        if(node == x)//For the usual LeetCode LCA problem, p and q are actual node pointers. It's safer to search for the node itself:
        // Otherwise, if two nodes somehow have the same value, your function could find the wrong node.
        return true;

        if(getPath(ans, node->left, x) || getPath(ans, node->right, x))
        return true;

        ans.pop_back();
        return false;//If that particular node is not found

        }
		
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return NULL;

        vector<TreeNode*> p1;
        getPath(p1, root, p);

        vector<TreeNode*> p2;
        getPath(p2, root, q);

        //We have stored the path of that node starting from the root node for both the nodes so the last matched node will be our Lowest common ancestor

        int size = min(p2.size(), p1.size());
        TreeNode* Lca = NULL;
        for(int i = 0; i < size; i++){
            if(p1[i] == p2[i]){
                Lca = p1[i];
            }
            else break;
        }
        return Lca;
    }
};/*BRUTE FORCE:
Getting the root-to-node path for both the nodes and matching the nodes
T.C. = O(2N + N), S.C. = O(2N) + {Recursive stack space}*/