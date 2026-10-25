#include <iostream>
using namespace std;

int deciBinary(){
    int n;
    cout << "Enter the number: ";
    cin >> n;

    int rem, ans = 0, pow = 1;
    while(n > 0){
        rem = n%2;
        n /= 2;
        ans += rem*pow;
        pow *= 10;
    }
    cout << ans;
}
int main()
{
    cout << deciBinary()<<endl;
    return 0;
}