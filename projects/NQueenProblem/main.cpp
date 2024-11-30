#include <iostream>
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

int main()
{
	for (int i = 1; i <= 16; i++)
	{
		int counter = 0;
		int*q = new int[i];
		int c = 0;
		q[c] = -1;
		while (true)
		{
			if (c == i)
			{
				counter++;
			}
			q[c] = -1;
			while (true)
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
			if (c == -1)
				break;
			c++;
		}
		cout << "There are "<< counter << " solution for " << i << " queens." << endl;
	}
	return 0;
}