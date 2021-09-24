/* 20)Given a full m-ary tree with i internal vertices, 
Write a Program to find the number of leaf nodes.
*/

#include <iostream>
using namespace std;

int main() //main function
{
	int m, i, L;
	cout << "Enter the number of children each node can hava at max" << endl;
	cin >> m; //input children at each node max
	cout << "Enter the number of internal nodes" << endl;
	cin >> i;			 //input internal nodes
	L = i * (m - 1) + 1; //formula
	cout << "Leaf nodes = " << L << endl;

	return 0;
}