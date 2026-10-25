#include <iostream>
using namespace std;

int binaryDeci(){
    int n;
    cout << "Enter the number: ";
    cin >> n;

    int rem, ans = 0, pow = 1;
    while(n > 0){
        rem = n%10;
        n /= 10;
        ans += rem*pow;
        pow *= 2;
    }
    cout << ans;
}
int main()
{
    binaryDeci();
    return 0;
}