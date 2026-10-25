#include <iostream>
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
// M-1 with zero indexing
// int findHtDp(Node* root,int count){
//     if(root == NULL)return count;

   
//     int left = findHtDp(root->left, count + 1);

    
//     int right = findHtDp(root->right, count + 1);

//     int ans = max(left, right);
    
//     return ans;

// }
//With indexing of one
int findHtDp(Node* root){
    if(root == NULL)return 0;

    int left = findHtDp(root->left);
    if(left == -1)return -1;
    int right = findHtDp(root->right);
    if(right == -1)return -1;

    if(abs(left-right) > 1)return -1;
    return 1 + max(left, right);

}
bool check(Node* node){
    if(findHtDp(node) == -1)return false;
    else 
    return true;
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
  
    
    if(check(root)){
        cout << "Balanced B.T.";
    }
    else
    cout << "Unbalanced B.T.";
    
    return 0;
}//T.C. = O(N), S.C. = O(N){Recursive stack space in a skew tree}