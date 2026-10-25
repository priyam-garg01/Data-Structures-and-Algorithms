#include <iostream>
#include <vector>
#include <stack>
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

vector<int> inorder(Node* root){
    vector<int> ans;
    if(root == NULL)return ans;
    stack<Node*> st;
    Node* node = root;
    while(true){
        if(node){
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty())break;
            node = st.top();
            st.pop();
            ans.push_back(node->data);
            node = node->right;//if left node isn't available move to right
        }   
    }
    return ans;
    
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
    
    vector<int> ans = inorder(root);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    } 
    
    return 0;
}