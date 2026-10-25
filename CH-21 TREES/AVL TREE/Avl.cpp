#include<iostream>
using namespace std;

class Node{

    public:

    int data, height;
    Node *left, *right;
    
    Node(int val){
        data = val;
        height = 1;
        left = right = NULL;
    }
};

int getHt(Node* node){
    if(node == NULL){
        return 0;
    }

    return node->height;
}

int getBalance(Node* root){
    int left = getHt(root->left);

    int right = getHt(root->right);

    return left - right;
}

Node* leftRot(Node* root){
    //Firstly we memorize the left child of root->child
        Node* child = root->right;
        Node* childLeft = child->left;
        
        root->right = childLeft;
        child->left = root;//Rotated to the left

        //Update height of root and child
        root->height = 1 + max(getHt(root->left), getHt(root->right));
        //First root's height is updated as it affects  while finding height of child(currently neww root)
        child->height = 1 + max(getHt(child->left), getHt(child->right));
        

        //Returning correct address
        return child;

}
Node* rightRot(Node* root){
    //Firstly we memorize the right child of root->child
        Node* child = root->left;
        Node* childRight = child->right;

        root->left = childRight;
        child->right = root;//Rotated to the right

        //Update height of root and child
        root->height = 1 + max(getHt(root->left), getHt(root->right));
        child->height = 1 + max(getHt(child->left), getHt(child->right));

        //Returning correct address
        return child;

}

Node* insert(Node* root, int key){
    //If root doesn't exist
    if(root == NULL){
        return new Node(key);
    }

    //If root exists
       
    if(key > root->data){
        root->right = insert(root->right, key);
    }
    else if(key < root->data){
        root->left = insert(root->left, key);
    }
    else{//Duplicates aren't entertained
        return root;
    }

    //Update height
    root->height = 1 + max(getHt(root->left), getHt(root->right));

    //Balancing check
    int balance = getBalance(root);
    
    //Unbalancing cases:
    //Left left 
    if(balance > 1 && root->left->data > key){
        return rightRot(root);
    }

    //Right right
    else if(balance < -1 && root->right->data < key){
        return leftRot(root);
    }

    //Left right
    else if(balance > 1 && root->left->data < key){
        root->left = leftRot(root->left);//middle node
        return rightRot(root);
    }
    //Right left
    else if(balance < -1 && root->right->data > key){ 
        root->right = rightRot(root->right);//middle node
        return leftRot(root);
    }
    
    //Balanced  
    else{
        return root;
    }
}

Node* deleteNode(Node* root, int val){
        if(!root)return nullptr;

        if(val > root->data){
            root->right = deleteNode(root->right, val);
        }
        else if(val < root->data){
            root->left = deleteNode(root->left, val);
        }

        else{//Main deletion logic:
        // Case I & II: 0 or 1 child
        if(root->left == NULL || root->right == NULL){
            Node* temp = root->left ? root->left : root->right;
        
            if(temp == NULL){//0 child
               temp = root;
               root = NULL;
            }
            else{
                *root = *temp;//Copy contents
                
            }
            delete temp;
        }
            // C-II: Both children are present
            else if(root->left != NULL && root->right != NULL){

                //Move the lowest element in right subtree
                Node* Right = root->right;
                while(Right->left != NULL){
                    Right = Right->left;
                }

                root->data = Right->data;//Data change

              //  delete Right;
              /*delete Right; frees the memory for Right, but it leaves its parent node pointing to a 
                dangling pointer. Furthermore, if Right has a right child, that subtree is lost.*/
                root->right = deleteNode(root->right, root->data);

             //   return root; We have to check for height balancing
            }
        }
            
        if(root == NULL) return root;
            
            //Update height
        root->height = 1 + max(getHt(root->left), getHt(root->right));

        //Balancing check
        int balance = getBalance(root);

        //Unbalancing cases:

        //Left side
        if(balance > 1){
            //Left left
            if(getBalance(root->left) >= 0){//Means the unbalancing is due to left side of root->left
                return rightRot(root);
            }

            //Left right
            else{
                root->left = leftRot(root->left);
                return rightRot(root);
            }
        }

        //Right side
        else if(balance < -1){
            //Right right
            if(getBalance(root->right) <= 0){//Unbalancing is from right side
                return leftRot(root);
            }

            //Right left
            else{
                root->right = rightRot(root->right);
                return leftRot(root);
            }
        }

        //Balanced  
        else return root;

    }

    void preorder(Node* root){
        if(root == NULL){
            return;
        }

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

int main(){

    Node* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 5);
    root = insert(root, 100);
    root = insert(root, 95);

    cout <<"Preorder: " << endl;

    preorder(root);

    return 0;
}