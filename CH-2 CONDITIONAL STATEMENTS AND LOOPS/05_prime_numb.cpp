#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int prime;
    if(n == 0 || n ==1)
        cout << n << " is a Non Prime number" << endl;
    else{
        for(int i = 2; i < n; i++){
                if(n % i == 0)
                {
                    cout << n << " is a Non Prime number" << endl;
                    prime = 0;
                    break;
                }   
                else
                    prime = 1; 
                    break;       
            }
            if(prime == 1)
                cout << n << " is a Prime number" << endl;
            
        }



        return 0;
    }

