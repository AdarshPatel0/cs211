#include <iostream>

using namespace std;

int main(){
	int numSolutions = 0;
	int b[8][8]={},r,c=0; //Create a boards with 8 x 8 dimensions
	b[0][0]=1; //Put a queen in the first position
nextCol: c++; //Moves us to the next row
	if(c==8) goto print; //This can only happen if all queens are placed sucessfully.
	r=-1; //We start off at -1 since we increment right after.
nextRow: r++;
	if(r==8) goto backtrack; //We cannot put a queen on any row in this column, therefore we must go back to the prevoius column and find a new valid position for a queen.
	//Check for a queen on the same row
	for(int i = 0; i < c; i++)
		if(b[r][i]==1) goto nextRow;
	//Check for diagnol up
	for(int i = 1; i<=c && i<=r; i++)
		if(b[r-i][c-i]==1) goto nextRow;
	//Check for diagnol down
	for(int i = 1; (c-i)>=0 && (r+i)<8; i++)
		if(b[r+i][c-i]==1) goto nextRow;
	b[r][c]=1;
	goto nextCol;
backtrack: c--; //Go back 1 row
	if(c==-1) return 0; //If we go back too far, that means all options are exauhsted, and we must end.
	r=0; //Go back to start of row
	while(b[r][c]!=1) r++; //Find the queen on that row 
	b[r][c]=0; //Remove that queen
	goto nextRow;
print:
	cout << "Solution #" << ++numSolutions << ":\n"; //I Had to switch this to pre-increment since we start off at zero.
	for(int i = 0; i < 8 ;i++){ //Simple nested for loop to print 2d Array.
		for(int j = 0; j < 8;j++){
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	goto backtrack; //See of more options are possible if we choose another row on the previous column
}