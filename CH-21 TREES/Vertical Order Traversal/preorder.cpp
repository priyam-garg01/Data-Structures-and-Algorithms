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

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;

        map<int, map<int, multiset<int>>> nodes;//{Consists of the vertical level the horizontal level and the value of node {the mutiset is used to store the values of nodes which may be same that is why we havnt used set}}
        stack<pair<TreeNode*, pair<int, int>>> st;//The stack contains the node as well as the vertical and horizontal levels resp
        st.push({root,{0, 0}});
        while(!st.empty()){
            auto p = st.top();
            st.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(node->val);
            if(node->right){
                st.push({node->right, {x+1, y + 1}});
            }
            if(node->left){
                st.push({node->left, {x-1, y + 1}});
            }
        }
        for(auto p : nodes){
            vector<int> col;
            for(auto st : p.second){
    /*col.push_back(st.second);//st.second is a multiset so You need to insert all elements of the multiset:
 col.insert(col.end(), st.second.begin(), st.second.end()); ✅
            */
    col.insert(col.end(), st.second.begin(), st.second.end());
        }
            ans.push_back(col);
    }
    return ans;
    }
};