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
/*METHOD-I USING 2 STACKS
vector<int> postorder(Node* root){
    vector<int> ans;
    if(root == NULL)return ans;
    stack<Node*> st1, st2;
    st1.push(root);
    while(!st1.empty()){
         root = st1.top();
         st1.pop();
         st2.push(root);
         if(root->left)st1.push(root->left);
         if(root->right)st1.push(root->right);

    }
    while(!st2.empty()){
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
}//T.C. = O(2N), S.C. = O(2N)
    */

/*M-II USING A SINGLE STACK*/

vector<int> postorder(Node* root){
    vector<int> ans;
    if(root == NULL)return ans;
    stack<Node*> st;
    Node* curr = root;
    Node* temp = NULL;
    while(curr != NULL || !st.empty()){
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        else{
            temp = st.top()->right;
            if(temp == NULL){
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else{
                curr = temp;
            }
        }
        
    }
    return ans;
    
}//T.C. = O(2N), S.C. = O(N)

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    vector<int> ans = postorder(root);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    } 
    
    return 0;
}