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

vector<int> preorder(Node* root){
    vector<int> ans;
    if(root == NULL)return ans;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
            Node* node = st.top();
            st.pop();
            if(node->right)st.push(node->right);//we will push right node first as stack is a last in first out ds
            if(node->left)st.push(node->left);
            ans.push_back(node->data);
        }
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] <<  endl;
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

    preorder(root);
    
    return 0;
}//T.C. = O(N) + O(N){FOR ANS PRINTING}, S.C. = O(N){for height of tree = n having one right for every node} + O(N){FOR ANS STORING}