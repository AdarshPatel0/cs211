#include <iostream>
#include <vector>

using namespace std;

int const boardDim = 8;

class game{
	public:
	int board[boardDim][boardDim]={};
	int queensAvailable = 8;
	bool fail = false;
	vector<int> selectOrder = {};
	void placeQueen(int x ,int y){
		for(int i = 0; i<boardDim-1;i++){
			board[i][y]=1;
			board[x][i]=1;
		}
		for(int i = x; i<boardDim-1;i++){
			int yPosA=y+i-x;
			if(yPosA>=0 && yPosA<=boardDim-1){
				board[i][yPosA] = (board[i][yPosA]==2) ? 2:1;
			}
			int yPosB=y-(i-x);
			if(yPosB>=0 && yPosB<=boardDim-1){
				board[i][yPosB] = (board[i][yPosB]==2) ? 2:1;
			}
		}
		for(int i = x; i>=0;i--){
			int yPosA=y+i-x;
			if(yPosA>=0 && yPosA<=boardDim-1){
				board[i][yPosA] = (board[i][yPosA]==2) ? 2:1;
			}
			int yPosB=y-(i-x);
			if(yPosB>=0 && yPosB<=boardDim-1){
				board[i][yPosB] = (board[i][yPosB]==2) ? 2:1;
			}
		}
		board[x][y] = 2;
		queensAvailable--;
	}
	int spotsAvailable(){
		int available = 0;
		for(int y = 0;y<boardDim-1;y++){
			for(int x = 0;x<boardDim-1;x++){
				if(board[x][y]==0){
					available++;
				}
			}
		}
		return  available;
	}
};

void printBoard(game obj){
	for(int y = 0;y<boardDim-1;y++){
		for(int x = 0;x<boardDim-1;x++){
			cout << obj.board[x][y];
		}
		cout << endl;
	}
}

int main(){
	vector<game> games = {};
	while (true) {
		
	}

	return 0;
}