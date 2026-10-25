// Figure out how to find a number is 
// power of 2 without any loop
#include <iostream>
using namespace std;
/* A number n is a power of 2 if and only if:

n > 0

n & (n - 1) == 0

Reason:
A power of 2 has exactly one 1 bit in binary.
n - 1 flips all bits after that 1.
ANDing them results in 0.

Example

8 = 1000

7 = 0111

8 & 7 = 0000 → power of 2*/
int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    if(n > 0 && (n & (n-1)) == 0)
        cout << n << " is a Power of 2"<< endl;
    else
        cout << n << " is not a Power of 2"<< endl;
    return 0;
}









// // With loops
// #include <iostream>
// using namespace std;
// bool isPowerOfTwo(int n){
//     if(n <= 0){
//         cout << n << " is not a power of 2";
//         return false;
//     }
//     int n1 = n;

//     while(n1%2 == 0)
//         n1 /= 2;
//     if(n1 == 1){
//         cout << n << " is a power of 2";
//         return true;
//     }
//     else{
//         cout << n << " is not a power of 2";
//         return false;
//     }



// }
// int main()
// {
//     isPowerOfTwo(69);
// }













