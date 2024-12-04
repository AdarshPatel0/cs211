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

int main(){
	int counter = 0;
	int q[8] = {};
	int c = 0;
	q[c] = 0;
	while(c>-1){
		c++;
		q[c] = -1;
		if(c==8){
			c--;
			counter++;
		}
		while(q[c]<8){
			q[c]++;
			if(q[c]==8){
				c--;
			}
			else if(test(q, c)){
				break;
			}
		}
	}
	cout << counter << endl;
}