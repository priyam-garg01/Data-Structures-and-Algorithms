/*Given the root of a binary tree, return the top view of the binary tree.



The top view of a binary tree consists of the set of nodes visible when the tree is observed from above.



Return the values of these nodes ordered from the leftmost to the rightmost position.



If multiple nodes share the same horizontal distance from the root, only the node that appears first when traversing from left to right (i.e., the leftmost node) should be included in the result.


Example 1

Input : root = [1, 2, 3, 4, 5, 6, 7]

Output : [4, 2, 1, 3, 7]*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
    public:
    vector<int> topView(TreeNode *root){
        vector<int> ans;
        if(!root)return ans;

        //Using the same concept in vertical order traversal : Line order
        map<int, int> mpp;
        queue<pair<TreeNode*, int>> q;//Stores the node and its vertical level
        q.push({root, 0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            if(mpp.find(p.second) == mpp.end())mpp[p.second] = node->data;
            if(node->left){
                q.push({node->left, p.second - 1});
            }
            if(node->right){
                q.push({node->right, p.second + 1});
            }
        }
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
        
    }
};/*CAUTION: We cannot use the recursive inorder, preorder, postorder traversals as we get wrong entries into our 
queue first which disturbes our ans*/
/*T.C. = O(N) + O(N), S.C. = {O(D){MAP} -->O(N)} + O(N){QUEUE} + O(N){ANS}
T.C. = O(2N), S.C. = O(3N)*/