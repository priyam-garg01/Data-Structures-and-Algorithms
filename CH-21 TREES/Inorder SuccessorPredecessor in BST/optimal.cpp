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
    int successor(TreeNode* root, int key){
        TreeNode* curr = root;
        int succ = -1;
        while(curr){
            if(curr->data > key){
                succ = curr->data;
                curr = curr->left;
            }
            else {
                curr = curr->right;
                }
            }
        return succ;
        }

    
    int predecessor(TreeNode* root, int key){
        TreeNode* curr = root;
        int pred = -1;
        while(curr){
            if(curr->data < key){
                pred = curr->data;
                curr = curr->right;
            }

            else{
                curr = curr->left;
                }
            }
        return pred;
        }

    
		vector<int> succPredBST(TreeNode* root,int key){
        TreeNode* node = root;

        int pred;
        int succ;

            pred = predecessor(root, key);
            succ = successor(root, key);
           
            vector<int> ans;
            ans.push_back(pred);
            ans.push_back(succ);
            return ans;
		}
};/*Using the BST properties and moving the ptrs to correct place and meanwhile putting val to pred or 
succ if the condition satisfies
T.C. = O(H) = O(2LOGN) {SKEWED TREE O(2N)}, S.C. = O(1)*/