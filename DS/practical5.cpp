/*
 5) Write a Program to generate the Fibonacci Series using recursion.
*/

#include <iostream>
using namespace std;

class Fibonacci
{
public:
    Fibonacci()
    { //Default constructor
        int n = 0;
    }
    int fib(int n)
    { //Function to check Fibonacci
        if ((n == 0) || (n == 1))
        {
            return n;
        }
        else
        {
            return (fib(n - 1) + fib(n - 2));
        }
    }
    int input()
    { //Input function
        int n;
        cout << "\nEnter the number of terms of series: ";
        cin >> n;
        return n;
    }
};

int main()
{ //Main function
    Fibonacci f;
    int n = f.input();
    cout << "\nFibonacci Series is: ";
    int i = 0;
    while (i < n)
    {
        cout << " , " << f.fib(i);
        i++;
    }
    cout << endl;
    return 0;
}