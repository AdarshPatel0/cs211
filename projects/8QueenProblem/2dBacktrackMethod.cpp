#include <iostream>

using namespace std;

int main(){
	int numSolutions = 0;
	int b[8][8]={},r,c=0;
	b[0][0]=1;
nextCol: c++;
	if(c==8) goto print;
	r=-1;
nextRow: r++;
	if(r==8) goto backtrack;
	//row test
	for(int i = 0; i < c; i++)
		if(b[r][i]==1) goto nextRow;
	for(int i = 1; i<=c && i<=r; i++)
		if(b[r-i][c-i]==1) goto nextRow;
	for(int i = 1; (c-i)>=0 && (r+i)<8; i++)
		if(b[r+i][c-i]==1) goto nextRow;
	b[r][c]=1;
	goto nextCol;
backtrack: c--;
	if(c==-1) return 0;
	r=0;
	while(b[r][c]!=1) r++;
	b[r][c]=0;
	goto nextRow;
print:
	cout << "Solution #" << ++numSolutions << ":\n"; //I Had to switch this to pre-increment since we start off at zero.
	for(int i = 0; i < 8 ;i++){
		for(int j = 0; j < 8;j++){
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	goto backtrack;
}