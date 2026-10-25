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
            if(curr->left == NULL){
                if(curr->data > key && succ == -1){
                    succ = curr->data;
                    }
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
                    if(curr->data > key && succ == -1)succ = curr->data;
                        curr = curr->right;
                    }
                }
            }
        return succ;
        }

    
    int predecessor(TreeNode* root, int key){
        TreeNode* curr = root;
        int pred = -1;
        while(curr){
            if(curr->left == NULL){
                if(curr->data < key){
                    pred = curr->data;
                }
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
                        if(curr->data < key)pred = curr->data;
                        curr = curr->right;
                    }
                }
            }
        return pred;
        }

    
		vector<int> succPredBST(TreeNode* root,int key){
			/*Brute: We can store the inorder traversal search for the key elem
            T.C. = O(N) + O(LOGN), S.C. = O(N)*/
            //For now we observe that if the element is just smaller then it will be predecessor of the key and the larger will be the successor
        TreeNode* node = root;
        int pred = INT_MIN;

        int succ = INT_MAX;
            pred = predecessor(root, key);
            succ = successor(root, key);
           
            vector<int> ans;
            ans.push_back(pred);
            ans.push_back(succ);
            return ans;
		}
};
/*Morris traversal to note down the predecessor and succ with T.C. = O(2N), S.C. = O(1)*/