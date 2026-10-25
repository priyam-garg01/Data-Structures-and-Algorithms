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
    back = nullptr;
    next = nullptr;
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
Node* removeHead(Node* head){
    // If empty
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node*temp = head;
    head = head->next;
    head->back = NULL;
    temp->next = nullptr;
    free(temp);
    return head;
}
Node* removeTail(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node*temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->back->next = NULL;
    temp->back = NULL;
    free(temp);
    return head;
}

int main(){
    vector<int> arr = {23, 56, 22, 98, 27};
    Node* head = convertArr2DLL(arr);
    head = removeHead(head);
    print(head);
    cout << endl;   
    head = removeTail(head);
    print(head);


    return 0;
}