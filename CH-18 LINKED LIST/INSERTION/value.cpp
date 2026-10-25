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

Node* insertVal(Node* head, int inputval, int val){
    // Add a node before that node conatining val
    Node* newNode = new Node(inputval);
    if(head == NULL){
        return NULL;//as if list is empty there is no value before which we can insert the inputval
    }
    //If val is in the head node
    if(head->data == val){
        newNode->next = head;
        head = newNode;
        return head;
    }
    int found = 0;
/*W/O extra node*/
    Node*temp = head;
        while(temp->next != NULL){
            if(temp->next->data == val){
                newNode->next = temp->next;
                temp->next = newNode;
                found = 1;
                break;
            }
            temp = temp->next;
        }
/*With extra node
    Node*temp = head; Node* prev = NULL;
    while(temp != NULL){
        if(temp-> data == val){
            prev->next = newNode;
            newNode->next = temp;
            found = 1;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    */
   if(found == 0){
        cout << "VALUE NOT FOUND!" << endl;
   }
    return head;
}
int main(){
    vector<int> arr = {2, 5, 8, 7};
 Node* head = convertArr2LL(arr);   
 head = insertVal(head, 34, 4);
 print(head);
    return 0;
}