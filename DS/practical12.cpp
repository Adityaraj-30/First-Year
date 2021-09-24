/*For any number n, write a program to list all the solutions of the equation x1 + x2 + x3 + …+ xn = C,
 where C is a constant (C<=10) and x1, x2,x3,…,xn are nonnegative integers using brute force strategy.
 */

#include <iostream>
using namespace std;

void printArray(int p[], int s)
{

  for (int i = 0; i < s; i++)
    cout << " " << p[i];

  cout << endl;
}

void partitions(int c, int n)
{

  int p[c];

  int k = 0;

  p[k] = c;

  while (true)

  {

    if ((k + 1) == n)
      printArray(p, k + 1);
    int rem_val = 0;
    while (k >= 0 && p[k] == 1)
    {
      rem_val += p[k];

      k--;
    }

    if (k < 0)

      return;

    p[k]--;

    rem_val++;

    while (rem_val > p[k])

    {
      p[k + 1] = p[k];

      rem_val = rem_val - p[k];

      k++;
    }

    p[k + 1] = rem_val;

    k++;
  }
}

int main()
{

  int n, c;

  cout << "\n Enter an integer(c): ";

  cin >> c;

  cout << "\n Enter size of partitions(n): ";

  cin >> n;

  cout << "\n All Partitions of " << c << " of size " << n << ":" << endl;
  partitions(c, n);

  return 0;
}
