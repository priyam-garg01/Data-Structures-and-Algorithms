#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char str[] = {'2', '5', ',', 'r', 'g', '\0'};
    int tr[] = {4, 5, 6, 7, 8};
    cout << tr << endl;//integer array prints the address of 1st element

    cout << str << endl;//character come together to form a string "25,rg"

    cout << strlen(str) << endl;//null character is ignored
    

//Direct assigning & calculating length
    char euhk[] = "hello";
    // {'h', 'e', 'l', 'l', 'o', '\0'}
    int len = 0;
    for(int i = 0; i < str[i] != '\0'; i++){
        len++;
    }
    cout << "len of string is : " << len << endl;

    cout << euhk << endl;

// INPUT AND OUTPUT

    char you[100];

    cout << "enter char array : ";

    // cin >> you;
    //space ke baad waale charcters are ignored by cin
   // cin.getline(str_name, len_of_array, charact_to_stop_the_input);
    cin.getline(you, 100);

    cout << "output : " << you << endl;//only first word is printed

    // For printing individual characters("apna college")
    char str1[100];//12 char in string and 1 null charact
    cout << "enter char array : ";
    cin.getline(str1, 100, 'u');

    for(char ch : str1){
        cout << ch << "";
    } 
    cout << endl;










    return 0;
}