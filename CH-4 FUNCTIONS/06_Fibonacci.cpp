#include <iostream>
using namespace std;

void Fibonacci(int n)
{
    cout << "Fibonacci series till " << n << " is: "<< endl;
    int first = 0;
    int second = 1;
    int next;
    for (int i = 0; i < n; i++)
    {
        cout << first << "  ";

        next = first + second;
        first = second;
        second = next;
    }
}
int main()
{
    Fibonacci(7);
    return 0;
}