int ceil(TreeNode* node, int key){//T.C. = O(H)
        
        int ceil = -1;
        while(node){
            if(node->data == key){
                return node->data;
            }
            
            if(node->data > key){
                ceil = node->data;
                node = node-left;
            }
            else{
                node = node->right;
            }
        }
        if(found)return ceil;
        else return -1;
    }