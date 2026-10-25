#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> m;
    m["Lp"] = 100;
    m["JK"] = 100;
    m["JK"] = 10;

    cout << m["Lp"] << m.count("fo");
    
    if(m.find("Lp") != m.end()){
        cout << "found\n";
    }
    else
    return 0;
}