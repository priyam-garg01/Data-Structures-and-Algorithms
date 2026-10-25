#include<iostream>
using namespace std;

int main(){

// Arithmetic Operators
    int a = 45;
    double b = 4.5;

    cout << "Sum is " << a+b << endl;
    cout <<"Difference is "<< a-b << endl;
    cout << "Product is "<< a*b << endl;
    cout << "Quotient is "<< a/b << endl;
    cout << "Modulo is "<< a%int(b)<< endl;


// Relational operators->Returns bool '0' or '1'


    cout << (3 > 5) << endl;

    cout << (5 >= 2)<< endl;

    cout << (3 != 3)<< endl;




// Logical Operators
        // OR or DOUBLE PIPE(||)  
        // AND or DOUBLE AMPERSAND(&&)  
        // NOT (!)

    cout << !(3 >  5) << endl;

    cout << (3 > 89 || 45 > 0) << endl;

    cout << (34 > 78 && 4 > 2) << endl;



    return 0;


}