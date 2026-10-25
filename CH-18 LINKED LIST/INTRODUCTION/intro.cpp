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
    Node* convertArr2LL(vector<int> &arr){
        Node* head = new Node(arr[0]);
        Node* mover = head;
        for(int i = 1; i < arr.size(); i++){
            Node*temp = new Node(arr[i]);
            mover->next = temp;
            mover = temp;
        }
        return head;
    }
};

int main()
{
 vector<int> arr = {2, 5, 8, 7};
 Node p = Node(arr[0], nullptr);
// cout << p;   //throws error because it is an object either you can take data or pointer
    cout << p.data << "\n";
    cout << p.next << "\n";
 Node*y = new Node(arr[2], nullptr);
 cout << y << "\n";   //return a pointer

 Node*k = new Node(arr[3], nullptr);
 //cout << y.data;   //returns error as y is a pointer datatype
 cout << k->data << "\n";//returns the address   
 cout << k->next << "\n";   //returns the ptr of next node

 Node*q = new Node(arr[0], nullptr);
 cout << q->data;   //return data part at that memory location


    return 0;
}