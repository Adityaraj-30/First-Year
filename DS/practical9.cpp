/*
9. Write a Program to implement Insertion Sort. Find the number of comparisons during each pass
 and display the intermediate result. Use the observed values to plot a graph to analyse the 
 complexity of algorithm.
*/

#include <iostream>
using namespace std;

class insertion
{

public:
	int size;
	int *arr;

	//constructor
	insertion()
	{
		size = 0;
		arr = NULL;
	}

	//func to take input from user
	void enter()
	{

		cout << "ENTER SIZE OF ARRAY :";
		cin >> size;

		arr = new int[size]; //dynammically allocating size

		for (int i = 0; i < size; i++)
		{
			cout << "\n ENTER ELEMENT " << i + 1 << " : ";
			cin >> arr[i];
		}

		cout << "\n\n ENTERED ARRAY IS : ";
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << ",";
		}
	}

	//func to sort an array
	void sort()
	{

		int i, temp, j;
		int count = 0;

		//lets take second index value
		for (i = 1; i < size; i++)
		{
			temp = arr[i];
			j = i - 1;

			while (j >= 0 && arr[j] > temp)
			{
				arr[j + 1] = arr[j];
				j = j - 1;
				count++;
			}

			if (count >= 0)
			{
				cout << "\n\n NUMBER OF COMPARISON IN " << i << " PASS IS : " << count;
			}
			count = 0;
			arr[j + 1] = temp;
			print();
		}
	}
	void print() //print
	{
		cout << "\n\n\n ARRAY IS : ";

		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << ",";
		}
	}
};

int main()
{
	insertion I;

	I.enter();
	I.sort();
	cout << "\n\n SORTED ARRAY :";
	I.print();

	return 0;
}