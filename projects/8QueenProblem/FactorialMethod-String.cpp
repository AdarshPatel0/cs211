#include <iostream>

using namespace std;

void printBoard(char board[]){
	for(int i = 0;i<8;i++){
		for(int j = 0;j<8;j++){
			cout << ((j==board[i])?"1 ":"0 ");
		}
		cout << endl;
	}
	cout << endl;
}

bool checkDiagonal(char board[]){
	for(int i = 0;i<7;i++){
		for(int j = 1;j<8-i;j++){
			if(board[i]+j==board[i+j]||board[i]-j==board[i+j]){
				return false;
			}
		}
	}
	return true;
}

void buildBoard(char route[],int & routes){
	// vector<char> pool = {0,1,2,3,4,5,6,7};
	string pool = "01234567";
	char board[8]={};
	for(char i=7;i>=0;i--){
		board[i]=pool[route[i]]-'0';
		cout << route[i];
		pool.erase(route[i],1);
	}
	if(checkDiagonal(board)){
		printBoard(board);
		routes++;
	}
}

void calculateRoutes(char route[],char currentIndex,int &routes){
	char baseMax = currentIndex;
	char newBase = route[currentIndex]+1;
	if(newBase>baseMax){
		newBase = 0;
		route[currentIndex] = newBase;
		if(currentIndex+1<8){
			calculateRoutes(route, currentIndex+1,routes);
		}
		else {
			return;
		}
	}
	else {
		route[currentIndex] = newBase;
		buildBoard(route,routes);
		if(currentIndex>0){
			calculateRoutes(route, 0,routes);
		}
		else {
			calculateRoutes(route, currentIndex,routes);
		}
	}
}

int main(){
	int routes = 0;
	char currentRoute[8] = {-1,0,0,0,0,0,0,0};
	calculateRoutes(currentRoute,0,routes);
	cout << routes << " routes calculated." << endl;
	return 0;
}