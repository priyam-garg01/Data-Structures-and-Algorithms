#include<iostream>
using namespace std;

class Sum{
    public:

    int ans(int a, int b){
        return a + b;
    }

    string ans(string s1, string s2){
        return s1 + s2;
    }
};

class Complex{
    int real, img;

    public:
   
    Complex(){}

    Complex(int real, int img){
        this->real = real;
        this->img = img;
    }
    Complex operator +(Complex &C){
        Complex ans;
        ans.real = real + C.real;
        ans.img = img + C.img;
    }
    void display(){
        cout << real << " + " << img << "i" << endl;
    }

};

int main(){
    Sum S1;
    cout << S1.ans(3, 7) << endl;
    cout << S1.ans("Hell", "o") << endl;

    Complex C1(5, 6);
    C1.display();
    Complex C2(5, 22);

    Complex C3 = C1 + C2;
    C3.display();
    
    return 0;
}