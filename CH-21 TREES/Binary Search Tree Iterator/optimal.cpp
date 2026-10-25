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
class BSTIterator {
public:
stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        TreeNode* curr = root;

        while(curr){
            st.push(curr);
            curr = curr->left;
        }

    }
    
    int next() {
       TreeNode* node = st.top();
       int ans = node->val;
        /*st.pop();
        if(node->right){
        your loop starts with node itself (the popped node), which pushes it right back onto the stack and tries to go left again. This will mess up the inorder traversal order.
            while(node){
                st.push(node);
                node = node->left;
            }
        }*/
        node = node->right;
        st.pop();
        while(node){
            st.push(node);
            node = node->left;
        }
        return ans;
    }
    
    bool hasNext() {
        if(!st.empty())return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
/*OPTIMAL:
Using the left subtree part of iterative inorder traversal which stores all the leftmost nodes, and then in the next function we pop and check if the current node has any right members if yes then we insert all of them into that
T.C. = O(1) for both functions, because the time when we move to right averages down to 1= N/N {for n nodes}}
S.C. = O(H)*/