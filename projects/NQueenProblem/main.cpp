#include <iostream>
#include <unistd.h>

using namespace std;

bool test(int board[], int c)
{
	for (int n = 0; n < c; n++)
	{ // This loop will itterate through the previous columns
		if (board[n] == board[c])
		{ // This checks if another queens is on this row
			return false;
		}
		if (c - n == abs(board[c] - board[n]))
		{ // This checks for and queens diagnoly placed, by checking for the difference in row and column are the same
			return false;
		}
	}
	return true;
}

int nqueens(int n) //8 queens problem solver but instead of using 8, we use n as the number of queens.
{
	int *q = new int[n]; //Create a a dynamic array of size n to fit all n queens.
	int counter = 0;
	int c = 0;
	q[c] = 0;
	while (c > -1)
	{
		c++;
		q[c] = -1;
		if (c == n)
		{
			counter++;
			c--;
		}
		while (q[c]<n)
		{
			q[c]++;
			if (q[c] == n)
			{
				c--;
			}
			else if (test(q, c))
			{
				break;
			}
		}
		
	}
	delete[] q; //Delete the dynamic array
	return counter;
}

int main()
{
	int n = 12;
	for (int i = 1; i <= n; i++) //Loop through solutions for i amount of queens.
	{
		cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem." << endl;
	}
	return 0;
}