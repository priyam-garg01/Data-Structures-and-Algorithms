/*Given a root of binary search tree and a key(node) value, find the floor and ceil value for that particular key value.



Floor Value Node: Node with the greatest data lesser than or equal to the key value. 


Ceil Value Node: Node with the smallest data larger than or equal to the key value.


If a particular floor or ceil value is not present then output -1.


Example 1

Input : root = [8, 4, 12, 2, 6, 10, 14] , key = 11

Output : [10, 12]*/
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{	
	public:

    int floor(TreeNode* node, int key){//T.C. = O(H)
        if(!node)return -1;
        int maxi = -1;
        while(node){
            if(node->data <= key){
            maxi = node->data;
            }
            node = node->data > key ? node->left : node->right;
        }
        return maxi;
    }
    int ceil(TreeNode* node, int key){//T.C. = O(H)
        if(!node)return -1;
        int mini = -1;
      
        while(node){
            if(node->data >= key){
            mini = node->data;
           
            }
            node = node->data > key ? node->left : node->right;
        }
        return mini;
    }

		vector<int> floorCeilOfBST(TreeNode* root,int key){
			vector<int> ans;
            if(!root)return ans;

            ans.push_back(floor(root, key));
            ans.push_back(ceil(root, key));
            return ans;
		}
};/*Since we naturally move closer to the target key as we traverse down the BST, 
simply overwriting maxi and mini works perfectly and keeps the code clean.*/