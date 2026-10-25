#include <iostream>
using namespace std;

struct Node{

    int data;
    Node* left;
    Node* right;

    Node(int data1){
        data = data1;
        left = nullptr;
        right = nullptr;
    }
};



void preorder(Node* node){
    if(node == NULL){
        return;
    }
    cout << node->data << endl;
    preorder(node->left); 
    preorder(node->right);
    return;
}


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    preorder(root);
     
    return 0;
}//T.C. = O(N), S.C. = O(N){SKEW TREE}