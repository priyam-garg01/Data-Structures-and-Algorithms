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
Node* insertHeadBef(Node* head, int val){
     Node*temp = new Node(val, head, nullptr);
     head->back = temp;

     //Or simply return temp
     head = temp;
     return head;

}
Node* insertHeadAft(Node* head, int val){
     Node*temp = new Node(val, head->next, head);
     head->next->back = temp;
     head->next = temp;
     return head;
}

int main(){
    vector<int> arr = {3, 6, 1, 89, 4, 2};
    Node* head = convertArr2DLL(arr);
    head = insertHeadAft(head, 67);
    print(head);

    return 0;
}