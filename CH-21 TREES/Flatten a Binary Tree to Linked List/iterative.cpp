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

    void flatten(TreeNode* root) {
    if(!root)return;
    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()){
        TreeNode* node = st.top();
        st.pop();
        if(node->right){
            st.push(node->right);
        }
        if(node->left){
            st.push(node->left);
        }
        if(!st.empty()){
            node->right = st.top();
            node->left = NULL;
        }
    }
        
    }
};/*Iterative approach: Use a stack to put the rightmost element at last and initiate the node left to null and its right to the remaining element in the stack
T.C. = O(N), S.C. = O(N)*/