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
    //another constructor having only data field and ptr is assumed as null
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
Node* removesk(Node* head, int k){
    if(head == NULL||head->next == NULL)return NULL;
    if(k==1){
        Node*temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    //if k > length of LL
    int count = 0; Node*temp = head;Node*prev = NULL;
    while(temp != NULL){
        count++;
        if(count == k){//if k is between start and end or equal to end
            prev->next = temp->next;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if(k > count)return head;
    
    delete temp;//breaks connection of temp to its next and only its prev is connected to its next
    return head;
}


int main()
{
 vector<int> arr = {2, 5, 8, 7};
 Node* head = convertArr2LL(arr);   
 head = removesk(head, 1);
 print(head);
    return 0;
}