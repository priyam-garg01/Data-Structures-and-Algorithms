#include <iostream>
#include <cmath>
using namespace std;

bool isArmstrong(int n){
    int temp = n;
    int count = 0;

    // Step 1: count digits
    if(n == 0) count = 1;
    while(temp > 0){
        count++;
        temp /= 10;
    }

    // Step 2: calculate sum
    temp = n;
    int sum = 0;

    while(temp > 0){
        int digit = temp % 10;
        sum += (int)pow(digit, count);
        temp /= 10;
    }

    return sum == n;
}

int main(){
    int n = 153;

    if(isArmstrong(n)){
        cout << "Armstrong number" << endl;
    } else {
        cout << "Not Armstrong number" << endl;
    }

    return 0;
}