#include <iostream>
using namespace std;

void changeA(int* ptr){
    *ptr = 455;
}
void changeB(int &b){
    b = 45;
}
int main()
{
    int a = 89;
    int* ptry = &a;

    cout << a << endl;

    changeA(ptry);
    cout << a << endl;

    changeB(a);
    cout << a << endl;

    
    return 0;
}