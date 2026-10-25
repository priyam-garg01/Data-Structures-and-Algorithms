#include<iostream>
using namespace std;

int main(){
    string s = "Rohit";
    int size = 0;
    while(s[size] != '\0'){
        size++;
    }
    cout << size << endl;

    return 0;
}