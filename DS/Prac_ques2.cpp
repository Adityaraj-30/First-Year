// /* 2) Write a program to print number of steps to solve game of Tower of Hanoi using recursion.
//  Explain with the example the minimum number of moves required to transfer 3 disks from
//   rod A to rod B or C.
// */


#include <iostream>

using namespace std;

int sum = 0;

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) // towerOfHanoi function
{
    if (n == 1)
    {
        cout << "Move disk = 1 from rod " << from_rod << " to rod----> " << to_rod << endl;
        sum++;
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod); //Calling function
    cout << "Move disk = " << n << " from rod " << from_rod << " to rod----> " << to_rod << endl;
    sum++;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod); //Calling function
}

int main() //Main function
{
    int n;
    cout << "Enter the number of Disks" << endl; //Taking input
    cin >> n;
    towerOfHanoi(n, 'A', 'C', 'B');                           // A,B,C are name of rod
    cout << "\n Total number of moves taken:" << sum << endl; //total steps
    return 0;
}
