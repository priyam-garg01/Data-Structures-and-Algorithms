/*Given the root node of a binary search tree (BST) and an integer key. Return the Inorder predecessor 
and successor of the given key from the provided BST.

Note: key will always present in given BST.

If predecessor or successor is missing then return -1.

Example 1
Input : root = [5, 2, 10, 1, 4, 7, 12] , key = 10
Output : [7, 12]


Example 2
Input : root = [5, 2, 10, 1, 4, 7, 12] , key = 12
Output : [10, -1]*/
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
    vector<int> inorderMorr(TreeNode* root){
        TreeNode* curr = root;
        vector<int> inorder;
        while(curr){
            if(curr->left == NULL){
                    inorder.push_back(curr->data);
                    curr = curr->right;
                }
                else{
                    TreeNode* prev = curr->left;
                    while(prev->right && prev->right != curr){
                        prev = prev->right;
                    }
                    if(!prev->right){
                        prev->right = curr;
                        curr = curr->left;
                    }
                    else{
                        prev->right = NULL;
                        inorder.push_back(curr->data);
                        curr = curr->right;
                    }
                }
            }
            return inorder;
        }
        int binarySearch(vector<int> vec, int key){
            int i = 0;
            int j = vec.size()-1;
            
            while(i <= j){
                int mid = i + (j-i)/2;

                if(vec[mid] == key)return mid;

                if(vec[mid] > key){
                    j = mid - 1;
                }
                else{
                    i = mid + 1; 
                }
            }
            return -1;
        }
    
		vector<int> succPredBST(TreeNode* root,int key){
			/*Brute: We can store the inorder traversal search for the key elem
            T.C. = O(N) + O(LOGN), S.C. = O(N)*/
            //For now we observe that if the element is just smaller then it will be predecessor of the key and the larger will be the successor
        TreeNode* node = root;

        vector<int> inorder = inorderMorr(root);
        int pred = -1;
        int succ = -1;

        int index = binarySearch(inorder, key);

        if(index > 0){
            pred = inorder[index-1];
        }

        if(index < inorder.size() - 1){
            succ = inorder[index + 1];
        }
            vector<int> ans;
            ans.push_back(pred);
            ans.push_back(succ);
            return ans;
		}
};/*T.C. = O(N) + O(LOGN), S.C. = O(N)*/