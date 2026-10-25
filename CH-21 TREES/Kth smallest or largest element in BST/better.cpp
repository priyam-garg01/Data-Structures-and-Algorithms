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
//RECURSIVE
class Solution {
    public:
    
    void inorder(TreeNode* node, vector<int>& ans){
        if(!node)return;
        
        inorder(node->left, ans);
        ans.push_back(node->val);
        inorder(node->right, ans);
        
        return ;
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root)return -1;
        TreeNode* node = root;
        
        //We can use the inorder traversal as it will give the sorted list of elements in a BST
        vector<int> ans;
        inorder(root, ans);
        
        if(k <= ans.size()){
            return ans[k - 1];
        }
        return -1;
        
    }
};
/*Better approach: (RECURSIVE)
Using Inorder traversal to resolve the sorting issue
T.C. = O(N), S.C. = O(N) + O(N) = O(2N)*/

//ITERATIVE
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root)return -1;
        TreeNode* node = root;

    //We can use the inorder traversal as it will give the sorted list of elements in a BST
        vector<int> ans;
        stack<TreeNode*> st;
    while(true){
        if(node){
            st.push(node);//this goes to extreme left
            node = node->left;
        }
        else{
            if(st.empty())break;
            node = st.top();
            st.pop();
            ans.push_back(node->val);
            node = node->right;
        }
    }
    // this gives us a sorted array via inorder traversal
    if(k <= ans.size()){
        return ans[k - 1];
    }
    return -1;

    }
};/*Better approach: (ITERATIVE)
Using Inorder traversal to resolve the sorting issue
T.C. = O(N), S.C. = O(N) + O(N) = O(2N)*/