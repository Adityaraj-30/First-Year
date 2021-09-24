//  7. Write a Program to implement binary search using recursion.

#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class binary  //creating binary class
{

public:
	int size;
	int *arr;
	int num;

	binary()
	{
		size = 0;
		arr = NULL;
		num = 0;
	}

	void enter()  //input function
	{

		cout << "ENTER SIZE OF ARRAY :";
		cin >> size;

		arr = new int[size];

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

		cout << "\n ENTER NUMBER YOU WANT TO SEARCH: ";
		cin >> num;
	}

	void BinarySearch(int L, int H)  //search function
	{

		int mid;
		if (L <= H)
		{

			mid = (L + H) / 2;

			if (arr[mid] == num)
			{

				cout << "\n \n Number is found at " << mid << " index \n";
			}

			else if (num > arr[mid])
			{

				BinarySearch(mid + 1, H);
			}

			else if (num < arr[mid])
			{

				BinarySearch(L, mid - 1);
			}
		}
		else
		{
			cout << "\n NUMBER NOT FOUND.";
		}
	}
};

int main()  //main function
{
	binary b;
	b.enter();
	int L = 0;
	int H = b.size - 1;
	sort(b.arr, b.arr + b.size);

	cout << "\n SORTED ARRAY IS : ";
	for (int i = 0; i < b.size; i++)
	{
		cout << b.arr[i] << ",";
	}

	b.BinarySearch(L, H);

	return 0;
}