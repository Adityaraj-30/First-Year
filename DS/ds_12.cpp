/*Practical 12-For any number n, write a program to list all the solutions of the equation x1 + x2 + x3 + …+ xn = C,
 where C is a constant (C<=10) and x1, x2,x3,…,xn are nonnegative integers using brute force strategy.
 */

#include <iostream>
using namespace std;
void display(int b[], int n) //Display function
{
	for (int i = 0; i < n; i++)
	{
		cout << " " << b[i] << " ";
	}
	cout << endl;
}
int combos(int b[], int k, int n, int c) //Combs function
{
	if (k == 0)
	{
		b[k] = c;
		display(b, n);
		return 0;
	}
	for (int i = 0; i <= c; i++)
	{
		b[k] = i;
		combos(b, k - 1, n, c - i);
	}
}
int main() //Main funcftion
{
	int n, c;
	cout << "Enter array size 'n': "; //Input
	cin >> n;
	int b[n];
	cout << "Enter sum 'c' between (1 to 10): ";
	cin >> c;
	while (!(c >= 0 && c <= 10)) //Check C
	{
		cout << "Invalid entry for c !!!, c should be between (1 to 10). " << endl;
		cout << "\nPlease try again!\n";
		cin >> c;
	}
	cout << "\n All Combination of " << c << " of size " << n << " are :\n"
		 << endl;
	combos(b, n - 1, n, c);
	return 0;
}
