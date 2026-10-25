#include <iostream>
using namespace std;

bool isAlphaNum(char ch){
    if((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z'))
    return true;
    else
    return false;
}

int main()
{
    
    string str = "racecar";
    int st = 0, end = str.length() - 1;
//OR USE isalnum() from <cctype> library
    while(st <= end){
        if(!isAlphaNum(str[st])){
            st++;
            continue;
        }
        if(!isAlphaNum(str[end])){
            end--;
            continue;
        }

        if(tolower(str[st]) != tolower(str[end])){
            cout << "NOT A PALINDROME";
            return 0;
        
        }
        st++, end--;
    }
    cout << str << " is a palindrome" << endl;

    return 0;
}