#include <vector>
#include <queue>
#include <utility>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::pair<std::vector<int>, std::vector<int>> getLeftAndRightView(TreeNode* root) {
    if (!root) {
        return {{}, {}};
    }
    
    std::vector<int> left_view;
    std::vector<int> right_view;
    std::queue<TreeNode*> q;
    
    q.push(root);
    
    while (!q.empty()) {
        int level_size = q.size();
        
        for (int i = 0; i < level_size; ++i) {
            TreeNode* curr = q.front();
            q.pop();
            
            // First node of the level -> Left View
            if (i == 0) {
                left_view.push_back(curr->val);
            }
            // Last node of the level -> Right View
            if (i == level_size - 1) {
                right_view.push_back(curr->val);
            }
            
            if (curr->left) {
                q.push(curr->left);
            }
            if (curr->right) {
                q.push(curr->right);
            }
        }
    }
    
    return {left_view, right_view};
}
//T.C. = O(N), S.C. = O(2N)