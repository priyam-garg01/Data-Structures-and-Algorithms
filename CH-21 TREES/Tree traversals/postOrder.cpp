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



void postorder(Node* node){
    if(node == NULL){
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout << node->data << endl;
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

    postorder(root);
     
    return 0;
}