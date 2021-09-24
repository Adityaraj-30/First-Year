/* Program - 13 : WAP to print the truth table of following logical operations for variables
x and y :
Conjunction , Disjunction , Exclusive OR , Conditional , Bi-conditional , Exclusive NOR ,
Negation , NAND , NOR.
*/
#include <iostream>
#include <iomanip>

using namespace std;

void printTT(int x1, int y1)
{
	if (x1 & y1 == 1) //Checking Conjunction
		cout << " \t  T";
	else
		cout << " \t  F";
	if (x1 | y1 == 1) //Checking Disjunction
		cout << "\t\t T";
	else
		cout << "\t\t F";
	if (x1 ^ y1 == 1) //Checking XOR
		cout << " \t     T";
	else
		cout << " \t     F";
	if ((!x1) | y1 == 1) //Checking Conditional
		cout << " \t \t   T";
	else
		cout << " \t \t   F";
	if ((x1 & y1) | ((!x1) & (!y1)) == 1) //Checking Bi-Conditional
		cout << " \t \t \t T";
	else
		cout << " \t \t \t F";
	if (x1 ^ y1 == 0) //Checking XNOR
		cout << " \t \t \t T";
	else
		cout << " \t \t \t F";
	if (!x1 == 1) //Checking Negation X
		cout << " \t   T";
	else
		cout << " \t   F";
	if (!y1 == 1) //Checking Negation Y
		cout << " \t      T";
	else
		cout << " \t      F";
	if (!(x1 & y1) == 1) //Checking NAND
		cout << " \t T";
	else
		cout << " \t F";
	if (!(x1 | y1) == 1) //Checking NOR
		cout << "    T";
	else
		cout << "    F" << endl;
}

int main()
{
	int x1, y1;
	char x, y;
	do
	{
		cout << "Enter the truth value of x and y respectively in form T or F" << endl;
		cin >> x >> y;
		if (x == '0' || y == '0' || x == '1' || y == '1')
			cout << "Invalid Input PLEASE TRY AGAIN" << endl;
	} while (x == '0' || y == '0' || x == '1' || y == '1'); //Taking input values of x and y till user gives input in T and F
	if (x == 'T')
		x1 = 1;
	else
		x1 = 0;
	if (y == 'T')
		y1 = 1;
	else
		y1 = 0;
	cout << "PRINTING TRUTH TABLE \n"
		 << endl;
	cout << "\n================================================================================================================================\n"
		 << endl;
	cout << "x | y | Conjunction | Disjunction | Exclusive (OR) | Conditional | Bi-Conditional | Exclusive (NOR) | Negation | Negation | NAND | NOR  |" << endl;
	cout << "\n---------------------------------------------------------------------------------------------------------------------------------\n"
		 << endl;
	cout << x << "  " << y;
	printTT(x1, y1);
	cout << "------------------------------------------------------------------------------------------------------------------------------------\n";
	return 1;
}