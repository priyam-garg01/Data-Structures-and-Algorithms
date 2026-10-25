
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* back;
    Node(int data1, Node*next1, Node*back1){
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
void print(Node*head){
    while(head != nullptr){
        cout << head->data << "\n";
        head = head->next;
    }
}

void reverseDll(Node* head){//T.C. = O(3N/2), S.C. = O(1)
    if(head == NULL|| head->next == NULL){
        return;
    }
    Node* front = head;
    Node* backL = head;
    int length = 1;
    while(backL->next != NULL){
        length++;
        backL = backL->next;
    }
    //We need to know the length of arr to figure out where to stop
        int k = 0;
        while(k != length/2){
            swap(front->data, backL->data);
            k++;
            front = front->next;
            backL = backL->back;
        }
        return;
}

int main(){
    vector<int> arr = {2, 5, 8, 7};
 Node* head = convertArr2DLL(arr); 
 print(head);
 cout <<endl;
 reverseDll(head);
 print(head);
    return 0;
}