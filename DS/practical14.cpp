/*14) Write a program to accept an input n from the user and graphically represent
 the values of T(n) where n varies from 0 to n for the recurrence relations. 
 For e.g. T(n) = T(n-1) + n, T(0) = 1, T(n) = T(n-1) + n^2, T(0) =1,
 T(n) = 2*T(n)/2 + n, T(1)=1
*/

#include <iostream>
using namespace std;

int func1(int n) //To calculate recursive relation T(n-1)+n
{
  if (n == 0)
    return 1;
  else
  {
    cout << "\n\n----->"
         << "T(" << n - 1 << ")"
         << "+" << n << " = " << n << endl;
    return func1(n - 1) + n;
  }
}

int func2(int n) //To calculate the recursive relation T(n-1)+n*2
{
  if (n == 0)
    return 1;
  else
  {
    cout << "\n\n-----> "
         << "T(" << n - 1 << ")"
         << "+" << n * 2 << " = " << n * 2 << endl;
    return func2(n - 1) + n * 2;
  }
}

int func3(int n) //To calculate the recursive relation 2*T(n/2)+n
{
  if (n == 1)
    return 1;
  else
  {
    cout << "\n\n-----> "
         << "2*T(" << n / 2 << ")+" << n << " = " << 2 * n << endl;
    return 2 * func3(n / 2) + n;
  }
}
int main()
{
  char ch = 'y';
  while (ch == 'y' || ch == 'Y')
  {
    cout << "\nPress (1) To calculate the recurssive relation T(n-1)+n \n";
    cout << "\nPress (2) To calculate the recurssive relation T(n-1)+n*2 \n";
    cout << "\nPress (3) To calculate the recurssive relation 2*T(n/2)+n \n";
    int n, m;
    cout << "\n\nPlease Enter your Choice____\n";
    cin >> n;
    cout << "\n\nEnter the value of n --> ";
    cin >> m;
    if (n == 1)
      cout << "\nOutput is given by: " << func1(m) << endl;
    else if (n == 2)
      cout << "\nOutput is given by: " << func2(m) << endl;
    else
      cout << "\nOutput is given by: " << func3(m) << endl;
    cout << "\nPress y/Y for continuing the program______ ";
    cin >> ch;
    cout << "\n";
  }
}