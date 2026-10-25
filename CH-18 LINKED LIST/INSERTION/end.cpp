#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = NULL;//or next is nullptr
    }
};
Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node*mover = head;
    for(int i = 1; i <arr.size(); i++){
        Node*temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void print(Node*head){
    
    while(head != NULL){
        cout << head->data << endl;
        head = head->next;
    }
}
Node* insertTail(Node* head, int val){
    if(head == NULL){
        return new Node(val, head);
    }
    Node* newNode = new Node(val);//At the ned temp->next points to null
    Node*temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        }
        temp->next = newNode;
    return head;
}
int main(){
     vector<int> arr = {2, 5, 8, 7};
 Node* head = convertArr2LL(arr);   
 head = insertTail(head, 782333);
 print(head);
    return 0;
}