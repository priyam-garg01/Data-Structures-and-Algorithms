class Solution{
    void changeToChildrenSum(BinaryTreeNode <int> * root){
        if(!root)return;
        int child = 0;
        
        if(root->left){
            child += root->left->data;
        }
        if(root->right){
            child += root->right->data;
        }
        
        if(root->val < child)root->value = child;
        
        else{
            root->left->data = root->data;
            root->right->data = root->data;
        }
        
        changeToChildrenSum(root->left);
        changeToChildrenSum(root->right);
        
        //After the updated left and right
        int tot = 0;
        if(root->left)tot += root->left->data;
        if(root->right)tot += root->right->data;
        //when the given node is not a leaf node only then its value get updated 
        if(root->left || root->right)root->data = tot;
    }
 };//T.C. = O(N), S.C. = O(H)->O(N)