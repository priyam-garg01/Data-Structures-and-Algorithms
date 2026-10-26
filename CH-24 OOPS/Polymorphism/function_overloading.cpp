#include<iostream>
using namespace std;

class Area{
    
    public:
    int calcArea(int r){
        return 3.14*r*r;
    }
    int calcArea(int l, int b){
        return l*b;
    }


};

int main(){
    Area A1, A2;
    cout << A1.calcArea(5) << endl;
    cout << A1.calcArea(4, 6) << endl;

    // cout<< A1.calcArea("Rohan");//no instance of overloaded function "Area::calcArea" matches the argument list

    return 0;
}