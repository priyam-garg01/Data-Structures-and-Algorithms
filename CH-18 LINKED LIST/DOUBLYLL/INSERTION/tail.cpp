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
Node* insertBefTail(Node* head, int val){
    if(head == NULL){
        return new Node(val);
    }
    if(head->next == NULL){
        Node* newNode = new Node(val, head, NULL);
        return newNode;
    }
    Node*tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* prev = tail->back;//If only one element prev = null and this next block doent execute
    Node*temp = new Node(val, tail, prev);
    if(prev != NULL){
        prev->next = temp;
    }
    tail->back = temp;
    return head;

}
Node* insertAftTail(Node* head, int val){
    if(head == NULL){
        return new Node(val);
    }
    Node*tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node*temp = new Node(val, nullptr, tail);
    tail->next = temp;
    return head;

}

int main(){
    vector<int> arr = {3, 6, 1, 89, 4, 2};
    Node* head = convertArr2DLL(arr);
    head = insertBefTail(head, 4);
    print(head);

    return 0;
}