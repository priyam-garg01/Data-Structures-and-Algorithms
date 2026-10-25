#include <iostream>
using namespace std;
void swapMinMax(int arr[], int size){
    // For min
    int value1 = 0;
    for (int i = 0; i < size; i++)
    {
        value1 = min(arr[i], value1);
    }
    // For max
    int value2 = 0;
    for (int i = 0; i < size; i++)
    {
        value2 = max(arr[i], value2);
    }
    cout <<"Max value: "<< value2 << endl;
    cout <<"Min value: "<< value1 << endl;
    swap(value1, value2);
    cout << "After swapping\n"<<"Max value: "<<value2<<endl;
    cout <<"Min value: "<<value1<<endl;


}
int main()
{
    int num[5] = {5677, 782, 0 , 37383, -23};
    swapMinMax(num, 5);
    
    return 0;
}