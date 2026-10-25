#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data1, Node*next1){
        data = data1; 
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
        
    }
};


Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i <arr.size(); i++){
            Node* temp = new Node(arr[i]);
            mover-> next = temp;
            mover = temp;
        }
        return head;
}
void print(Node*head){
    while(head != nullptr){
        cout << head->data << "\n";
        head = head->next;
    }
}

void reverseDll(Node* head){//T.C. = O(2N), S.C. = O(N)
    stack<int> st;
    Node* temp = head;
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return;
}

int main(){
    vector<int> arr = {2, 5, 8, 7};
 Node* head = convertArr2LL(arr); 
 print(head);
 cout <<endl;
 reverseDll(head);
 print(head);
    return 0;
}