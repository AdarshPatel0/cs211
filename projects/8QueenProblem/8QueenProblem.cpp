#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool const rowMap[8][8]={
{1,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0},
{0,0,0,1,0,0,0,0},
{0,0,0,0,1,0,0,0},
{0,0,0,0,0,1,0,0},
{0,0,0,0,0,0,1,0},
{0,0,0,0,0,0,0,1}
};

void incrementBoard(char currentBoard[],int i,bool &overflow){
	int baseSum = currentBoard[i]+1;
	if(baseSum>7){
		baseSum=0;
		if(i+1>7){
			overflow = true;
			return;
		}
		currentBoard[i]=baseSum;
		incrementBoard(currentBoard, i+1,overflow);
	}
	else {
		currentBoard[i]=baseSum;
	}
}

bool verifyBoard(char board[]){
	for(int i = 0;i<8;i++){
		for(int j = 0;j<8;j++){
			if(i!=j){
				if(board[i]==board[j]){
					return false;
				}
			}
		}
	}
	for(int i = 0;i<7;i++){
		for(int j = 1;j<8-i;j++){
			if(board[i]+j==board[i+j]||board[i]-j==board[i+j]){
				return false;
			}
		}
	}
	return true;
}

void printBoard(int combo){
	for(int i=0;i<8;i++){
		int glyph = ((int)(combo/pow(10, i))%10);
		for(int j=0;j<8;j++){
			cout << rowMap[glyph][j];
		}
		cout << endl;
	}
	cout << endl;
}

int convertToInt(char board[]){
	int base10rep=0;
	for(int i=0;i<8;i++){
		int base = ((int)board[i])*(pow(10,i));
		base10rep = base10rep+base;
	}
	return base10rep;
}

int main(){
	vector<int> validBoards = {};
	bool overflow = false;
	char currentBoard[8] = {};
	int generatedCounter = 0;
	int validCounter = 0;
	while (overflow==false) {
		if(verifyBoard(currentBoard)==true){
			validBoards.push_back(convertToInt(currentBoard));
			validCounter++;
		}
		incrementBoard(currentBoard, 0, overflow);
		generatedCounter++;
	}
	cout << generatedCounter << " possible combinations." << endl;
	cout << validCounter << " valid combinations." << endl;
	cout << "Printing all solutions..." << endl;
	for(int i = 0;i<validBoards.size();i++){
		printBoard(validBoards[i]);
	}
	return 0;
}