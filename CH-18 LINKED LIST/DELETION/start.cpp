#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node{
  //  public://No need of public as it is by default public
    int data;
    Node* next;
    // public:
    Node(int data1, Node* next1)
    {
        data = data1;
        next = next1;
    }
    //Nother constructor having only data field and ptr is assumed as null
    // public:  
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node*convertArr2LL(vector<int> &arr){//T.C. = O(N)
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node*temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void print(Node*head){
    while(head != NULL){
        cout << head->data << "\n";
        head = head->next;
    }
    cout << endl;
}
Node* removesHead(Node* head){
    if(head == NULL)return head;
    Node*temp = head;
    head = head->next;
    delete temp;
    return head;
}


int main()
{
 vector<int> arr = {2, 5, 8, 7};
 Node* head = convertArr2LL(arr);   
 head = removesHead(head);
 print(head);
    return 0;
}