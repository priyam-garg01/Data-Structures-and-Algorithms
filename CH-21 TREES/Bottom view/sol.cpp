/*Given root of binary tree, return the bottom view of the binary tree.



The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom. Return nodes from the leftmost node to the rightmost node. Also if 2 nodes are outside the shadow of the tree and are at the same position then consider the node that appears later in level traversal.


Example 1

Input : root = [20, 8, 22, 5, 3, null, 25, null, null, 10 ,14]

Output : [5, 10, 3, 14, 25]

Explanation : From left to right the path is as follows :

First we encounter node with value 5.

Then we have nodes 8 , 10 but from bottom only 10 will be visible.

Next we have 20 , 3 but from bottom only 3 will be visible.

Next we have 14 , 22 but from bottom only 14 will be visible.

Then we encounter node with value 25.*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
  public:
    vector <int> bottomView(TreeNode *root){
    	vector<int> ans;
        if(!root)return ans;
        map<int, int> mpp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int line = p.second;
            TreeNode* node = p.first;
            mpp[line] = node->data;
            if(node->left){
            q.push({node->left, line - 1});
        }
            if(node->right){
            q.push({node->right, line + 1});
            }
        }

        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};//Same concept of line traversal, same T.C. and S.C. as in top view
//We can use a stack and later do same approach as in top view but it takes an extra time complexity of O(N)