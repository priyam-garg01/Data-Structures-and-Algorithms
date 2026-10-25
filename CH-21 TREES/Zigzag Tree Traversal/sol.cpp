/*Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []*/
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

    
    
    void zigzaglevel(TreeNode* root, vector<vector<int>> &ans){
        if(root == NULL)return;
        queue<TreeNode*> q;
        q.push(root);
        int side = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
               
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                level.push_back(node->val);
                }
            
            if(side == 0){//left to right
                side = 1;
            }
            else {//right to left and reverse the level
                side = 0;
                reverse(level.begin(), level.end());
            }

            ans.push_back(level);
        }
     
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        zigzaglevel(root, ans);

    return ans;
    }
};/*BETTER: introducing a variable and changes its val to change the sides and using the reverse function to optimize the final output
T.C. = O(3N), S.C. = O(3N)*/
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

    
    
    void zigzaglevel(TreeNode* root, vector<vector<int>> &ans){
        if(root == NULL)return;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
               

                //Find the position to fill node's value
                int index = leftToRight ? i : (size - i - 1);
                level[index] = node->val;

                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                }
            
            //After this level
            leftToRight = !leftToRight;

            ans.push_back(level);
        }
     
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        zigzaglevel(root, ans);

    return ans;
    }
};/*OPTIMAL:
Initiating the size of the level early and introducing variable bool to manage to mangae the position of entering the node->val helps remove the extra time complexity of reverse function
T.C. = O(2N), S.C. = O(N) + O(N) + O(N)*/