#include <iostream>
using namespace std;

int main()
{
    string str = "apna college";//stored in continuous memory
    //dynamic => runtime resize
    cout << str << endl;
    
    str = "hello";//string is resized to hello
    cout << str << endl;
    
    char chArr[] = "apna collge";
    chArr - "hello";// cannot be changed on runtime

    cout << chArr << endl;

    string str1 = "viola";
    string str2 = "voila";
    cout << (str1 == str2) << endl;
    cout << (str1.length() == str2.length()) << endl;


// INPUT AND OUTPUT
    string str3;

    getline(cin, str3, 'o');

    for(char ch : str3){
        cout << ch << " ";
    }
    cout << endl;
    for(int i = 0; i < str3.length(); i++){
        cout << str3[i] << " ";
    }
    cout << "output : " << str3 << endl;
    return 0;
}