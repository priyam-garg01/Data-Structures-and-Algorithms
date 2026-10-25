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
Node* insertBefK(Node* head, int k, int val){
    if(k == 1){
        Node* newNode = new Node(val, head, nullptr);
        if(head == NULL){
            return newNode;
        }
            head->back = newNode;
            return newNode;
        
    }
    Node*temp = head;
    int cnt = 0;
    Node* prev = nullptr;
    while(temp != NULL){
        cnt++;
        if(cnt == k)break;
        prev = temp;
        temp = temp->next;
    }
    if(cnt == k - 1){//add an element before null i.e. add a tail after prev
        Node* newNode = new Node(val, nullptr, prev);
            prev->next = newNode;
            return head;
        
    }
    else if(k > cnt + 1){
        return head;
    }

    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}
Node* insertAftK(Node* head, int k, int val){
    if(head == NULL){
        return head;
    }
    if(k == 1){
    Node* front = head->next;
    Node* newNode = new Node(val, front, head);
    head->next = newNode;
    if(front != NULL){
        front->back = newNode;
    }
        return head;
    }
    Node* temp = head;
    int cnt = 0;
    Node* front = nullptr;
    while(temp != NULL){
        cnt++;
        if(cnt == k)break;
        temp = temp->next;
        // front = temp->next;//no nedd to track front during traversal
    }
    if(temp == NULL){//if k is greater than count
        return head;
    }
    front = temp->next;
    Node* newNode = new Node(val, front, temp);
    temp->next = newNode;
    if(front == NULL){
    return head;
}
    front->back = newNode;
    return head;
}

int main(){
    vector<int> arr = {3, 6, 1, 89, 4};
    Node* head = convertArr2DLL(arr);
    head = insertAftK(head, 6, 78);
    print(head);

    return 0;
}