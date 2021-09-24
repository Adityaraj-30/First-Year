//16) Write a Program to represent Graphs using the Adjacency Matrices and check if it is a
// completeGraphCheck graph.

#include <iostream>

using namespace std;

class adjacent
{ //class adjacent

public:
	int vertex;
	int *set;
	int edge;
	int **arr;

	adjacent()
	{
		vertex = 0;
		set = NULL;
		edge = 0;
		arr = NULL;
	}

	void enter() //input function
	{
		cout << "\n Enter the no. of Vertices you want to have :: ";
		cin >> vertex;
		cout << "\n Enter the no. of Edges you want to have :: ";
		cin >> edge;

		set = new int[vertex];
		for (int i = 0; i < vertex; i++)
		{
			set[i] = i + 1;
		}
		arr = new int *[vertex];
		for (int i = 0; i < 10; i++)
			arr[i] = new int[vertex];
	}

	void pairs()
	{
		int a, b;

		for (int i = 0; i <= vertex; i++) //initalizing matrix with zero at all positions.
		{
			for (int j = 0; j <= vertex; j++)
			{
				arr[i][j] = 0;
			}
		}

		for (int i = 0; i < edge; i++)

		{

			cout << "\nEnter pair " << (i + 1) << " of adjacent vertices:\n"
				 << endl;

			cin >> a >> b;
			if (a > vertex || b > vertex)
			{
				cout << "\nINVALID INPUT GREATER THAN TOTAL VERTEX.";
				cout << "\n ENTER AGAIN!.";
				cin >> a >> b;
			}

			else if (arr[a][b] == 1 || arr[b][a] == 1)
			{
				arr[a][b] += 1;
				arr[b][a] += 1;

				cout << "\n MULTIGRAPH EDGES!!";
				cout << "\nPLEASE TRY AGAIN.";
			}
			else
			{

				arr[a][b] = 1;
				arr[b][a] = 1;
			}
		}

		showmatrix();
	}

	bool completeGraphCheck()
	{
		bool flag1 = false, flagDia = false;
		for (int i = 1; i <= vertex; i++)
		{
			for (int j = 1; j <= vertex; j++)
			{
				if (arr[i][j] != 1 && (i != j))
				{
					return false;
				}
				if (arr[i][j] == 1 && (i == j))
				{
					return false;
				}
			}
		}
		return true;
	}

	void showmatrix()
	{

		cout << "\nThe Adjacency matrix is:\n"
			 << endl;
		for (int i = 0; i <= vertex; i++)
		{
			for (int j = 0; j <= vertex; j++)
			{
				if (i == 0 && j == 0)
					cout << "  ";
				else if (i == 0)
					cout << set[j - 1] << " ";
				else if (j == 0)
					cout << set[i - 1] << " ";
				else
				{

					cout << arr[i][j] << " ";
				}
			}
			cout << endl;
		}
	}
};

int main()
{ //main function

	adjacent a;

	a.enter();
	a.pairs();
	if (a.completeGraphCheck())
	{
		cout << "\nIT IS A COMPLETE GRAPH. " << endl;
	}
	else
	{
		cout << "\nIT IS NOT A COMPLETE GRAPH. " << endl;
	}

	return 0;
}
