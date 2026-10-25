#include <iostream>
#include <vector>
using namespace std;

int main()
{
// INITIALIZATION OF VECTOR
// M-1
    vector<int> vec;//Intially size is zero
    vec = {1, 2, 3};
    cout << vec[0] << endl;
    cout << vec[1] << endl;
    cout << vec[2] << endl;
// M-2
    vector<int> vec1 = {1, 5, 6};
    cout << vec1[0] << endl;
    cout << vec1[1] << endl;
    cout << vec1[2] << endl;
    
// M-3
    vector<int> vec2(3, 0); 
    //vec(size of vector, value at each index)
    cout << vec2[0] << endl;
    cout << vec2[1] << endl;
    cout << vec2[2] << endl;


    // Vector loop
    vector<char> vecch = {'a', 'b', 'c', 'd', 'e'};
    for(char value : vecch)
    {
        // Here 'value' is the value at the index
        cout << value << endl;
    }
    return 0;

}