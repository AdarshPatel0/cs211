#include <iostream>
#include <unistd.h>

using namespace std;

bool test(int board[], int c)
{
	for (int i = 0; i < c; i++)
	{ // This loop will itterate through the previous columns
		if (board[i] == board[c])
		{ // This checks if another queens is on this row
			return false;
		}
		if (c - i == abs(board[c] - board[i]))
		{ // This checks for and queens diagnoly placed, by checking for the difference in row and column are the same
			return false;
		}
	}
	return true;
}

void simulate(int i)
{
	int *q = new int[i];
	int counter = 0;
	int c = 0;
	q[c] = 0;
	while (c > -1)
	{
		c++;
		q[c] = -1;
		if (c == i)
		{
			counter++;
			c--;
		}
		while (q[c]<i)
		{
			q[c]++;
			if (q[c] == i)
			{
				c--;
			}
			else if (test(q, c))
			{
				break;
			}
		}
		
	}
	cout << "There are " << counter << " solution for " << i << " queens." << endl;
	delete[] q;
	return;
}

int main()
{
	for (int i = 1; i <= 16; i++)
	{
		simulate(i);
	}
	return 0;
}