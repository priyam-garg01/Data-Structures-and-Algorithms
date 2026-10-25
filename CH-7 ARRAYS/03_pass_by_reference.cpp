#include <iostream>
using namespace std;
/* In C++, arrays are passed to 
functions by reference by default.
This means changes made inside the function 
affect the original array.

Why?

->arr[] is treated as int* arr
->The function receives the address 
of the first element.
->No copy of the array is created
->int arr[] and int* arr are equivalent
 in function parameters.
*/
void changeArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        arr[i] = 2*arr[i];
    }
}
int main()
{
    int num[6] = {67488, -827272, 898, 28, 20, 0};

    changeArray(num, 6);

    for(int i = 0; i < 6; i++){
        cout << num[i] << endl;
    }
    return 0;
}