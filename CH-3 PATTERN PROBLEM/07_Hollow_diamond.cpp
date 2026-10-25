#include <iostream>
using namespace std;

int main()
{
    // Hollow diamond
    // for n = 4
    //       *
    //     *   *
    //   *       *
    // *           *
    //   *       *
    //     *   *
    //       *

    int n = 20;
    // Top part
    for(int i = 0; i < n; i++){
        // First for front spaces(Inverted triangle)
        for(int j = 0; j < n - i-1; j++){
            cout << " " << " ";
        }
        cout << "* "; //For front stars
        if(i != 0){
            // Second for middle spaces
            for(int j = 0; j < 2*i-1 ; j++){
                cout << " " << " ";
            }
        
            cout << "* "; // For behind starts
        }
        cout << endl;
    }
    // Bottom part(For bottom n-> n-1)
    for(int i = 0; i < n-1; i++){
        // First for front spaces(Simple triangle)
        for(int j = 0; j < i + 1; j++){
            cout << " " << " ";
        }
        cout << "* "; //For front stars
        
        if (i != n-2)
        {
            // Second for middle spaces
        for(int j = 0; j < 2*(n-2 -i)-1 ; j++){
            cout << " " << " ";
        }
        
        cout << "* "; // For behind starts
    }
        cout << endl;
    }
    return 0;
}