#include <iostream>

using namespace std;

int main(){
	int q[8] = {0,0,0,0,0,0,0,0};
	char bq[5][7] = {
	{' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', '\xdb', ' ', '\xdb', ' ', '\xdb', ' '},
	{' ', '\xdb', '\xdb', '\xdb', '\xdb', '\xdb', ' '},
	{' ', '\xdb', '\xdb', '\xdb', '\xdb', '\xdb', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	char wq[5][7] = {
	{'\xdb', '\xdb', '\xdb', '\xdb', '\xdb', '\xdb', '\xdb'},
	{'\xdb', ' ', '\xdb', ' ', '\xdb', ' ', '\xdb'},
	{'\xdb', ' ', ' ', ' ', ' ', ' ', '\xdb'},
	{'\xdb', ' ', ' ', ' ', ' ', ' ', '\xdb'},
	{'\xdb', '\xdb', '\xdb', '\xdb', '\xdb', '\xdb', '\xdb'}
	};
	char bb[5][7] = {
	{'\xdb', '\xdb', '\xdb', '\xdb', '\xdb', '\xdb', '\xdb'},
	{'\xdb', '\xdb', '\xdb', '\xdb', '\xdb', '\xdb', '\xdb'},
	{'\xdb', '\xdb', '\xdb', '\xdb', '\xdb', '\xdb', '\xdb'},
	{'\xdb', '\xdb', '\xdb', '\xdb', '\xdb', '\xdb', '\xdb'},
	{'\xdb', '\xdb', '\xdb', '\xdb', '\xdb', '\xdb', '\xdb'}
	};
	char wb[5][7] = {
	{' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' '}
	};
	typedef char box[5][7];
	box * board[8][8]{};
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if((i+j)%2==0){
				board[i][j] = &bb;
			}
			else {
				board[i][j] = &wb;
			}
		}
	}
	for(int i = 0; i < 8; i++){
		if((i+q[i])%2==0){
			board[i][q[i]] = &wq;
		}
		else {
			board[i][q[i]] = &bq;
		}
	}
	for(int i = 0; i < 8; i++){
		for(int k = 0; k < 5; k++){
			for(int j = 0; j < 8; j++){
				for(int l = 0; l < 7; l++){
					cout << (*board[i][j])[k][l];
				}
			}
			cout << endl;
		}
	}
	return 0;
}