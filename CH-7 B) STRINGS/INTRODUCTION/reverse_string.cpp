#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    int st = 0; int end = s.size() - 1;

    while(st < end){
        swap(s[st++], s[end--]);
    }
    cout << s;
    return 0;
}