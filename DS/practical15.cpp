/* Program - 15 : Write a program to store a polynomial function and then evaluate the
polynomial. */

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int deg, coeff[100], i, n, ans = 0;
    do
    {
        cout << "\n\n Enter the degree of polynomial you want to have : "; //Taking degree of poly
        cin >> deg;
    } while (deg < 0 || deg > 100);

    for (i = deg; i >= 0; i--)
    {
        cout << "\n\n Enter the coefficient for degree " << i << " : "; //Taking coefficient of degree
        cin >> coeff[i];
    }
    cout << "\n\n Polynomial entered is f(x) = ";
    for (i = deg; i >= 0; i--)
    {
        if (i == 0)
            cout << coeff[i];
        else if (i == 1)
            cout << coeff[i] << ".x";
        else
            cout << coeff[i] << ".x^" << i;

        if (i != 0)
            cout << " + ";
    }
    cout << "\n\n Enter the value for n for which you want to find f(n) : "; //Taking the value of n
    cin >> n;
    for (i = deg; i >= 0; i--)
    {
        ans += pow(n, i) * coeff[i];
    }
    cout << "\n\n f(" << n << ") = " << ans << "\n\n";
    return 0;
}
