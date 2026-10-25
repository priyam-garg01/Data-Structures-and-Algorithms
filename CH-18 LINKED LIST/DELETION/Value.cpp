#include<stdio.h>
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

Node* removesVal(Node* head, int val){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    //If val is in the head node
    if(head->data == val){
        Node*temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int count = 0; Node*temp = head; Node* prev = NULL;
    while(temp != NULL){
        if(temp-> data == val){
            prev->next = temp->next; 
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    delete temp;
    return head;
}
int main(){
    vector<int> arr = {2, 5, 8, 7};
 Node* head = convertArr2LL(arr);   
 head = removesVal(head, 5);
 print(head);
    return 0;
}