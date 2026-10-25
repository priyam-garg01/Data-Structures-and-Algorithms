int floor(TreeNode* node, int key){//T.C. = O(H)
       int floor = -1;
       while(node){
        if(node->data == key){
            return node->data;
        }
        if(node->data < key){
            floor = node->data;//No need of max as we are searching in BST
            node = node->right;
        }
        else{
            node = node->left;
        }
       }
       return floor;
    }