/* 
  Name: Practical Prg 1
  Author: Aditya Raj
  Roll no=5815
  Description:Write a Program to create a SET A and determine the cardinality of SET for an input array of elements (repetition allowed) and perform the following operations on the SET:    
        a)ismember (a, A): check whether an element belongs to set or not and return value as true/false.	 
        b)powerset(A): list all the elements of power set of A.

 */

#include <iostream>
#include <cmath>
using namespace std;

class Set
{
	int *arr;
	int n;

public:
	Set()
	{
		n = 0;
		arr = 0;
	}

	void setsize(); //To get set size

	void input_set(); //To input set

	void showset(); //To display set

	void uniqueset(); //To remove duplicate

	int cardinal(); //To find cardinality of set

	bool is_member(int); //To find is member or not

	void powerset(); //To display power set
};

void Set::setsize()
{
	cout << "\nEnter Size Of Array : ";
	cin >> n;
	arr = new int[n];
}

void Set::input_set()
{
	cout << "\nEnter Elements of the set : ";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

void Set::showset()
{
	cout << "THE SET IS : {";
	for (int i = 0; i < n - 1; i++)
	{
		cout << arr[i] << " ,";
	}
	cout << arr[n - 1];
	cout << "}";
}

void Set::uniqueset()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] == arr[j])
			{
				for (int k = j; k < n; k++)
				{
					arr[k] = arr[k + 1];
				}
				n--;
				j--;
			}
		}
	}
}

int Set::cardinal()
{
	return n;
}

bool Set::is_member(int num)
{
	for (int i = 0; i < n; i++)
	{
		if (num == arr[i])
		{
			return true;
		}
	}
	return false;
}

void Set::powerset()
{
	cout << '\n';
	int cnt = pow(2, n);
	cout << "{";
	cout << "{null} ";
	for (int i = 1; i < cnt; i++)
	{
		cout << "{";
		int temp = i;
		for (int j = 0; j < n; j++)
		{
			if (temp & 1)
			{
				cout << arr[j] << " , ";
			}
			temp = temp >> 1;
		}
		cout << "} ,";
	}
	cout << "}";
}

int main()
{
	//SET OBJECT
	Set a;
	a.setsize();
	a.input_set();
	int n;

	cout << endl;
	a.showset();
	cout << endl;
	a.uniqueset();
	int y = 1;
	while (y)
	{
		cout << "\n---------ENTER CHOICE :---------- ";
		cout << "\n1 : Cardinality";
		cout << "\n2 : Check Member";
		cout << "\n3 : Power set" << endl;
		cout << endl;
		cin >> n;
		cout << endl;
		if (n == 1)
		{
			a.showset();
			cout << "\nTHE CARDINALITY OF SET IS :";
			cout << a.cardinal();
		}
		else if (n == 2)
		{
			int num;
			cout << "\nENTER NUMBER : ";
			cin >> num;
			cout << endl;
			if (a.is_member(num))
			{
				cout << "\nTHE ELEMENT YOU ENTERED IS A MEMBER";
			}
			else
			{
				cout << "\nTHE ELEMENT YOU ENTERED NOT A MEMBER";
			}
		}
		else if (n == 3)
		{
			a.powerset();
		}

		else
		{
			cout << "\nINVALID CHOICE";
			y = 1;
		}
		cout << "\nWANT TO TRY AGAIN(y/n) :";
		char choice;
		cin >> choice;
		if ((choice != 'y') && (choice != 'Y'))
		{
			y = 0;
		}
		else
		{
			y = 1;
		}
	}
}