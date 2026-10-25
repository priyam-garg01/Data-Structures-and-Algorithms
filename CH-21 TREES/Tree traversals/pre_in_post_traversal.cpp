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

void order(Node* root){
    vector<int> pre;
    vector<int> in;
    vector<int> post;
    if(root == NULL)return;
    stack <pair<Node*,int>> st;//stores the node and its number (not data but its number)
    st.push({root, 1});
    
    while(!st.empty()){
        root = st.top().first;
        if(st.top().second == 1){
            pre.push_back(st.top().first->data);
            st.top().second++;
            if(root->left){
                root = root->left;
                st.push({root, 1});
            }
        }
        else if(st.top().second == 2){
            in.push_back(st.top().first->data);
             st.top().second++;
            if(root->right){
                root = root->right;
                st.push({root, 1});
            }
        }
        else if(st.top().second == 3){
            post.push_back(st.top().first->data);
            st.pop();
        }
    }
    int n = in.size();
    for(int i = 0; i < n; i++){
        cout << pre[i] << endl;
    }
    cout << endl;
    for(int i = 0; i < n; i++){ 
        cout << in[i] << endl;
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << post[i] << endl;
    }
    cout << endl;

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

    order(root);
     
    return 0;
}//T.C. = O(3N), S.C. = O(4N)