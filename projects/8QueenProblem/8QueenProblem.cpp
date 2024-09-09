#include <iostream>
#include <vector>

using namespace std;

void incrementBoard(bool currentBoard[],int i,bool &overflow){
    int baseSum = currentBoard[i]+1;
    if(baseSum>1){
        baseSum=0;
        if(i+1>63){
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

void printBoard(bool board[]){
    for(int i=0;i<64;i++){
        cout << board[i];
    }
    cout << endl;
}

/*
Valid map
2
4
8
16
32
64
128
256
*/

int main(){
    vector<bool[64]> setA;
    bool overflow = false;
    bool currentBoard[64] = {};
    while (overflow==false){
        incrementBoard(currentBoard, 0, overflow);
        printBoard(currentBoard);
    }
    return 0;
}