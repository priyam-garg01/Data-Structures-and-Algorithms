#include <iostream>
#include <queue>
using namespace std;

struct Node{


    int val;
    Node* left;
    Node* right;

    Node(int data1){
        val = data1;
        left = nullptr;
        right = nullptr;
    }
};

int findHtDp(Node* root){
    if(root == NULL)return 0;
    queue<Node*> q;
    q.push(root);
    int ans = 0;
    while(!q.empty()){
        ans++;//We are about to process a full level as we have run a loop till every node from each level has been accessed
        for(int i = 0; i < q.size(); i++){
            Node* node = q.front();
            q.pop();
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
    }
    return ans;
}


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(6);
    root->right->left->left = new Node(5);
    root->right->right->right = new Node(7);
  
    
    cout << findHtDp(root)-1;
    
    return 0;
}