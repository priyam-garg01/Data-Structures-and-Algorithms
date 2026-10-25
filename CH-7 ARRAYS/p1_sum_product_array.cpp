#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3,4,5};
    // SUM
    int sum = 0;
    for(int i = 0; i < 5; i++){
        sum += arr[i];
    }
    cout << sum << endl;
    // PRODUCT
    int product = 1;
    for(int i = 0; i < 5; i++){
        product *= arr[i];
    }
    cout << product;


    return 0;
}