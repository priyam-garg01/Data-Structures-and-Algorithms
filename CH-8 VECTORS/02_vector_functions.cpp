#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<char> vecch = {'a', 'b', 'c', 'e'};
// SIZE OF VECTOR(vec.size())

    cout << "size = " << vecch.size() << endl;


// vec.push_back(element)
    // Appends elements at the last

    vecch.push_back('7');
    // vecch.push_back('90');
    // // warning: overflow in implicit constant conversion [-Woverflow]     
    vecch.push_back('9');
    vecch.push_back('8');
    cout << "size = " << vecch.size() << endl;


// vec.pop_back()
    // Deletes the last input element
    vecch.pop_back(); //8 is deleted

    cout << "size = " << vecch.size() << endl;


// vec.front()
    // Prints the value at the front(index 0)

    cout << "Front value = "<< vecch.front() << endl;

// vec.back()
    // Prints the value at the back(index n-1)

    cout << "Back value = "<< vecch.back() << endl;


// vec.at(i)
    // Prints the value at index i

    cout << "Value at index 2 = "<< vecch.at(2) << endl;
    
    
    for(char value : vecch)
    {
        cout << value << endl;
    }
    return 0;
}