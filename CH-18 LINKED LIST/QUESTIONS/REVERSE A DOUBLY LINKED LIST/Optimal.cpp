// Reversig pointers or links
//Head should be tail but it loses data altogether so we first need to adjust the middle nodes by prev and front pointers
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

Node* reverseDll(Node* head){//T.C. = O(N), S.C. = O(1)
    if(head == NULL|| head->next == NULL){
        return head;
    }
    Node*temp = head;
    Node*front = temp->next;
    Node*prev = NULL;
    // We need to reverse the next and back pointers of each node
    while(front != NULL){//Stops at the last node
        //here temp->next != null wrong condition as when front = null its next may be garbage pointer value

        //links reversal
        temp->next = prev;
        temp->back = front;
        /*another alternative for temp != null
        prev = temp->back
        temp->back = temp->next
        temp->next = prev
        temp = temp->back
        
        then after loop ends 
        head = prev->back
        as prev points to last node*/

    
        prev = temp;
        temp = front;
        front = front->next;
    }
    temp->next = prev;
    temp->back = NULL;
    head = temp;
    return head;
}

int main(){
    vector<int> arr = {2, 5, 8, 7};
 Node* head = convertArr2DLL(arr); 
 print(head);
 cout <<endl;
 head = reverseDll(head);
 print(head);
    return 0;
}