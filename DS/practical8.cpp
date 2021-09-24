/*
8. Write a Program to implement Bubble Sort. Find the number of comparisons during
 each pass and display the intermediate result. Use the observed values to plot a
  graph to analyse the complexity of algorithm.
*/

#include <iostream>
using namespace std;

class bubble
{

public:
	int size;
	int *arr;

	// constructor formed
	bubble()
	{
		size = 0;
		arr = NULL;
	}

	// function to take input from user..
	void enter()
	{
		cout << "ENTER SIZE OF ARRAY :";
		cin >> size;
		arr = new int[size]; //dynamically alloting the size

		for (int i = 0; i < size; i++)
		{
			cout << "\nENTER " << i + 1 << " ELEMENT OF ARRAY: ";
			cin >> arr[i];
		}

		cout << "\n ENTERED ARRAY IS: ";
		for (int j = 0; j < size; j++)
			cout << arr[j] << ",";
		cout << endl;
	}

	// func to swap elements of array
	void swap(int *n1, int *n2)
	{
		int temp = *n1;
		*n1 = *n2;
		*n2 = temp;
	}

	// A function to implement bubble sort

	void bubbleSort()
	{
		int i, j, count = 0;
		for (i = 0; i < size - 1; i++)
		{

			// Last i elements are already in place
			for (j = 0; j < size - i - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					swap(&arr[j], &arr[j + 1]);
					count++;
				}
			}

			//this will print the number of comparisons

			if (count > 0)
			{
				cout << "\nNUMBER OF COMPARISON IN  " << i + 1 << " PASS IS " << count;
				printArray();
			}
			count = 0;
		}
	}

	/* Function to print an array */
	void printArray()
	{
		int i;
		cout << "\n\n  ARRAY IS: ";
		for (i = 0; i < size; i++)
			cout << arr[i] << ",";
		cout << endl;
	}
};

// main function
int main()
{
	bubble b; //object created
	b.enter();
	b.bubbleSort();
	cout << "\n\n SORTED ARRAY IS : ";
	b.printArray();
	return 0;
}