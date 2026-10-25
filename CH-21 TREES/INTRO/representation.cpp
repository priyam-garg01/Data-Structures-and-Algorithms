#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

struct Node{

    
    int data;
    struct Node* left;
    struct Node* right;

    Node(int data1){
        data = data1;
        left = nullptr;
        right = nullptr;
    }

    
};

int main(){
    struct Node* root = new Node(5);
    
    root->left = new Node(6);

    root->right = new Node(7);

    cout << root->right->data;
    cout << root->left->data;
    cout << root->data;
    return 0;
}