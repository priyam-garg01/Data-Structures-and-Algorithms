#include<iostream>
using namespace std;

int main(){
    // char arr[] = {'A', 'c', 't'};
    // // cout << arr;//Prints garbage char "45RoÇ"

    // // for(int i = 0;i < sizeof(arr)/sizeof(arr[0]); i++)cout << arr[i];

    // char arr1[10];
    // cin >> arr1;/*Writing beyond array boundaries is, and always has been, Undefined Behavior (UB) in C++*/
    // /*The program may crash immediately*/
    // /*Characters beyond index 9 may overwrite adjacent stack memory.*/

    // arr1[5] = '\0';//Terminates after reading null char
    // cout << arr1;

    // string s = "rtty 4566";
    // // cin >> s;//Input takes only a single word
    // getline(cin, s);//Takes input unitill a new line is encountered
    // cout << s;

    string s1 = "Mohit";

    // cout << s.size() << " " << s + s1 << endl;
    // s1.append("p");
    // cout << s1 << endl;
    // s.pop_back();
    // cout << s << endl;

    // string s2 = s1 + 'r';
    // cout << s2;

    string s3;
    // // s3 = "rohit is a "good" boy";//error
    // s3 = "Rohit is a \"good\" boy";
    // cout << s3 << endl;

    cout << "\0";//Printing null char : Nothing is printed
    cout << "\\0" << endl; 

    return 0;
}