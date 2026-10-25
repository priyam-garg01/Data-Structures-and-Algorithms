#include <iostream>
using namespace std;

void revNum(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int n1 =n;

    int digit, rev = 0;
    while(n1){
        digit = n1%10;
        rev = rev*10 + digit;
        n1 /= 10;
    }
    cout << "Reverse of " << n << " is: "<< rev << endl;
}
int main()
{
    revNum();
    
    return 0;
}