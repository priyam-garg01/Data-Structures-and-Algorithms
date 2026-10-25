#include <iostream>
#include <queue>
using namespace std;

int main()
{
   priority_queue<int> q;//MaxHeap

    q.push(2);
    q.push(20);
    q.push(29);
    q.push(7);
    q.push(5);
    cout << q.size() << endl;
    while(!q.empty()){
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
   priority_queue<int, vector<int>, greater<int>> qS;//MaxHeap

    qS.push(2);
    qS.push(20);
    qS.push(29);
    qS.push(7);
    qS.push(5);
    cout << qS.size() << endl;
    while(!qS.empty()){
        cout << qS.top() << " ";
        qS.pop();
    }
    return 0;
}