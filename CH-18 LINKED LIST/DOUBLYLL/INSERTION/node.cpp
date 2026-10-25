#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1; 
        back = back1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
    Node* convertArr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head; 
}
void print(Node* head){

   while(head != NULL){
    cout << head->data<<endl;
    head = head->next;
   }
}
 void insertBefNode(Node*temp, int val){
    if(temp == NULL){
        return;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    
    if(prev != NULL){
        prev->next = newNode;
    }
    temp->back = newNode;
}
void insertAftNode(Node* temp, int val){
   if(temp == NULL){
        return;
    }
    Node* front = temp->next;
    Node* newNode = new Node(val, front, temp);
    if(front != NULL){
    front->back = newNode;
    }
    temp->next = newNode;
    
}

int main(){
    vector<int> arr = {3, 6, 1, 89, 4};
    Node* head = convertArr2DLL(arr);
    insertBefNode(head->next, 56);
    print(head);

    return 0;
}