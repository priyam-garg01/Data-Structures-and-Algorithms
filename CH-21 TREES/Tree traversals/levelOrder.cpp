#include <iostream>
#include <vector>
#include <queue>
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



vector<vector<int>> levelOrder(Node* root){
    vector<vector<int>> ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        vector<int> level;
        int size = q.size();//for inserting each nodes children present on each level
        for(int i = 0; i < q.size(); i++){
            Node* node = q.front();//to store the parent node and later put in vector
            q.pop();//To store only the children of that node in q such that next time that stored nodes are accessed their 
            // child gets into q and itself pops out
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }



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

    levelOrder(root);
  
     
    return 0;
}