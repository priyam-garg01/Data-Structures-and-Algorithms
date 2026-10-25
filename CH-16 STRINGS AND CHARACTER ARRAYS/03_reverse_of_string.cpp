#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string str = "apna college";
    cout << str << endl;

    // using character arrays
    int st = 0, end = str.length() - 1;

    while(st <= end){
        swap(str[st++], str[end--]);
    }

    cout << str << endl;

    reverse(str.begin(), str.end());
    cout << str << endl;

    return 0;
}