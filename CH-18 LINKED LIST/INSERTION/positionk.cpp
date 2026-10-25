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
Node* insertK(Node* head, int val, int k){
    if(head == NULL){
        if(k == 1){//missed edge case
        return new Node(val, head);
        }
        else return NULL;
    }
    Node* newNode = new Node(val);//At the end temp->next points to null
    if(k == 1){//missed egde case
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node*temp = head;
    /*Using extra node
     Node*prev = NULL;
    int count = 0;
    while(temp != NULL){
        count++;
        if(count == k){
            prev->next = newNode;
            newNode->next = temp;
            break;
        }   
        prev = temp;
        temp = temp->next;
    }
    */
    // Without using extra node
        int count = 0;
        while(temp != NULL){
            count++;
            if(count == k - 1){
                newNode->next = temp->next;
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }

    return head;
}
int main(){
     vector<int> arr = {2, 5, 8, 7};
 Node* head = convertArr2LL(arr);   
 head = insertK(head, 782333, 8);
 print(head);
    return 0;
}