#include <iostream>
using namespace std;

int sum_of_digits(int n){
   

    int digitSum = 0;

    while(n != 0){
        int remainder = n % 10;
        digitSum += remainder;
        n /= 10;
    }
    return digitSum;

}
int main()
{
     int n;
    cout << "Enter the number: ";
    cin >> n; 

    cout << "Sum of digits is " << sum_of_digits(n) << endl;
    
    
    return 0;
}