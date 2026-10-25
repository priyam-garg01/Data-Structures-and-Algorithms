/*Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the 
nodes you can see ordered from top to bottom.
Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]

Explanation:



Example 2:

Input: root = [1,2,3,4,null,null,null,5]

Output: [1,3,4,5]

Explanation:



Example 3:

Input: root = [1,null,3]

Output: [1,3]

Example 4:

Input: root = []

Output: []

 

Constraints:

The number of nodes in the tree is in the range [0, 100].
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root)return ans;
//To get the right side view we only need to insert the right nodes value by first traversing to the right side and then to the left side if at that horizontal level there is no node
    map<int, int> mpp;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while(!q.empty()){
        auto p = q.front();
        q.pop();
        int hz = p.second;
        TreeNode* node = p.first;
        if(node->right)q.push({node->right, hz + 1});
        if(node->left)q.push({node->left, hz + 1});


        if(mpp.find(hz) == mpp.end())mpp[hz] = node->val;
        }

        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};/*Iterative approach:
T.C. = O(2N), S.C. = O(3N)*/
// For left side view change right to left