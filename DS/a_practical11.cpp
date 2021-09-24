/* Program - 11 : Write a program to calculate permutation and combination for an input value n and r using recursive formula of
 P(n,r) and C(n,r). 
*/

#include <iostream>
using namespace std;

int nPr(int n, int r)
{
	if (r > n) //Checking if r is greater than n
		return 0;
	else if (r <= 0) //Base Case
		return 1;
	else
		return n * nPr(n - 1, r - 1);
}

int nCr(int n, int r)
{
	if (r > n) //Checking if r is greater than n
		return 0;
	else if (n == 0 || r == 0 || n == r) //Base Case
		return 1;
	else
		return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

void check(int n, int r) // Checking value of n and r (n should be >= r)
{
	if (n >= r)
	{
		cout << "\nUser has enter correct value of n and r...\n";
		return;
	}
	else
		cout << "\nWrong value of r (r>n) is entered by User...\n";
	exit(100);
}
int main() // Driver Code
{
	char ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		int n, r, s;
		cout << "\nEnter value of n: ";
		cin >> n;
		cout << "\nEnter value of r: ";
		cin >> r;
		check(n, r); // Calling check function
		cout << "\nEnter-> 1 for calculating the Permutation\n"
			 << "\nEnter-> 2 for calculating the Combination\n";
		cout << "\nEnter your choice: ";
		cin >> s;
		if (s == 1)
		{
			cout << "\n Permutation for n and r , P(" << n << "," << r << ") is :" << nPr(n, r) << endl; // Function Callling
		}
		else if (s == 2)
		{
			cout << "\nCombination for n and r , C(" << n << "," << r << ") is :" << nCr(n, r) << endl; // Function Calling
		}
		else
			cout << "\nWrong choice is entered by User\n"
				 << endl;
		cout << "\nEnter y or Y for continue the Program " << endl;
		cin >> ch;
	}
	return 0;
}