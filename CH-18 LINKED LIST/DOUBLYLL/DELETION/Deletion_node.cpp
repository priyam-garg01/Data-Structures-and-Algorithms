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


void removeNode(Node* temp){//Whatever node is given that is never the head of the DLL
   Node* prev = temp->back;
   Node* front = temp->next;

   if(front == NULL){
    prev->next = NULL;
    temp->back = NULL;
    delete temp;
   }
   prev->next = front;
   front->back = prev;
   temp->back =NULL;
   temp->next =NULL;
   delete temp;
}


int main(){
    vector<int> arr = {23, 8, 1, 9, 8};
    Node* head = convertArr2DLL(arr);
    removeNode(head);
    print(head);

    cout << endl;   
    
    // head = removeK(head, 3);
    // print(head);


    return 0;
}