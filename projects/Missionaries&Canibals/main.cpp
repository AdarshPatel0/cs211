#include <iostream>

using namespace std;

/*
Move set:
| M | C |5 Moves
| 1 | 0 |0
| 0 | 1 |1
| 1 | 1 |2
| 2 | 0 |3
| 0 | 2 |4

p[0] rightside missionaries
p[1] rightside canibals
p[2] leftside missionaries
p[3] leftside canibals
*/


int main(){
    int i=-1;
    int p[4]={3,3,0,0};
    int m[5]={};
nextMove: i++;
    if(i==5) goto print;
    m[i] = -1;
    cout << "Current side: " << i%2;
    goto nextType;
nextType: m[i]++;
    if(m[i]==5) goto backtrack;
    if(i>0){
        if(m[i]==m[i-1]){
            goto nextType;
        }
    }
    if(m[i] == 0){
        if((p[1+2*(i%2)]+1)>(p[0+2*(i%2)]+0)||(p[1+2*(i%2)]-1)>(p[0+2*(i%2)]-1)){
            goto nextType;
        }
    }
    if(m[i] == 1){
        if((p[1+2*(i%2)]+1)>(p[0+2*(i%2)]+1)||(p[1+2*(i%2)]-1)>(p[0+2*(i%2)]-1)){
            goto nextType;
        }
    }
    goto nextMove;
backtrack:
    i--;
    if(i==-1) return 0;
    goto nextType;
print:
    for(int i = 0; i < 6; i++){
        cout << i;
    }
    cout << endl;
    goto backtrack;
}