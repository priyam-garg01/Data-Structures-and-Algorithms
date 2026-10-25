/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/
struct NodeValue{
    int minNode, maxNode, maxSize;

    NodeValue(int minNode, int maxNode, int maxSize){
        this->maxSize = maxSize;
        this->minNode = minNode;
        this->maxNode = maxNode;
    }
};
class Solution{
    private:
        NodeValue largestBstHelper(TreeNode* root){
            //Base case if the the tree is empty size of bst is zero
            if(!root){
                return NodeValue(INT_MAX, INT_MIN, 0);
            }
            //Get values of max and min nodes from left and right
            auto left = largestBstHelper(root->left);
            auto right = largestBstHelper(root->right);

            //Check if current node is a valid bst
            if(root->data > left.maxNode && root->data < right.minNode){
        return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), 1 + left.maxSize + right.maxSize);
            }

            //If invalid bst
            return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
        }
	public:
		int largestBST(TreeNode* root){
			if(!root)return 0;
            return largestBstHelper(root).maxSize;
            
		}
};/*Using the postorder traversal to apply bottom to top approach for noting the max and min values from the down
T.C. = O(N), S.C. = O(H)*/