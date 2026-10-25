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
Node* removeK(Node* head, int k){
    // If empty
    if(head == NULL){
        return NULL;
    }
    
    int count = 0;
    Node* temp = head;


    while(temp != NULL){
        count++;
        if(count == k)break;
        temp = temp->next;
    }
    /*
    if(count < k){return head;}//if temp == null return head
    */
   if(temp == NULL){//k > length
        return head;
   }
    Node* prev = temp->back;
    Node* front = temp->next;


    if(k == 1){//To remove the head
        front->back = NULL;
        head = front;
        temp->next = NULL;
        temp->back = NULL;
        delete temp;
        return head;
    }
    else if(front == NULL){//check this after checking first position
        prev->next = front;//NULL
        // temp->next = NULL;//Already null
        temp->back = NULL;
        delete temp;
        return head;
    }
    //Remove middle node
        prev->next = front;
        front->back = prev;
        temp->next = NULL;
        temp->back = NULL;

        delete temp;
        return head;

    /*
    while(temp->next != NULL){//Does not account for k= last node
        count++;
        if(count == k){
            temp->back->next = temp->next;
            temp->next->back = temp->back;
            break;
        }
        temp = temp->next;
    }
    free(temp);
    return head;
    */
}
Node* removK(Node* head, int k){
    if(head == NULL){
        return head;
    }
    int count = 0; Node* temp = head;
    while(temp != NULL){
        count++;
        if(count == k)break;
        temp = temp->next;
    }
    if(k > count){
        return head;
    }
    Node* prev = temp->back;
    Node* front = temp->next;
    if(prev == NULL && front == NULL){//single node
       // delete head;
       // return head;//Returns free memory and not null
        return NULL;
    }
    else if(prev == NULL){//to remove head
        head = front;
        head->back = NULL;
        
        temp->next = NULL;
        delete temp;
        return head;
    }
    else if(front == NULL){//remove tail
        prev->next = NULL;
        temp->back = NULL;
        delete temp;
        return head;
    }
    //to remove from middle 
    prev->next = front;
    front->back = prev;
    temp->back = NULL;
    temp->next = NULL;
    delete temp;
return head;
}

Node* removeVal(Node* head, int val){
    if(head == NULL){
        return NULL;
    }
    Node* temp = head;
    int found = 0;
    while(temp != NULL){
        if(temp->data == val){
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if(found == 0){//If the value is not found
        return head;
    }

    Node*prev = temp->back;
    Node*front = temp->next;

    if(prev == NULL){
        head = head->next;
        temp->next = NULL;
        delete temp;
        return head;
    }
    if(front == NULL){
        prev->next = NULL;
        temp->back = NULL;
        delete temp;
        return head;
    }
    prev->next = front;
    front->back = prev;
    temp->back = NULL;
    temp->next = NULL; 
    return head;
    
}


int main(){
    vector<int> arr = {23, 8, 1, 9, 8};
    Node* head = convertArr2DLL(arr);
    head = removeVal(head, 23);
    print(head);

    cout << endl;   
    
    // head = removeK(head, 3);
    // print(head);


    return 0;
}