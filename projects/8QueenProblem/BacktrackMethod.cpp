#include <iostream>

using namespace std;

int main(){
    int counter = 0;
    int b[8][8]={},r,c=0;
    b[0][0]=1;
nc: c++;
    if(c==8) goto print;
    r=-1;
nr: r++;
    if(r==8) goto backtrack;
    //row test
    for(int i = 0; i < c; i++)
        if(b[r][i]==1) goto nr;
    for(int i = 1; i<=c and i<=r; i++)
        if(b[r-i][c-i]==1) goto nr;
    for(int i = 1; (c-i)>=0 and (r+i)<8; i++)
        if(b[r+i][c-i]==1) goto nr;
    b[r][c]=1;
    goto nc;
backtrack: c--;
    if(c==-1) return 0;
    r=0;
    while(b[r][c]!=1) r++;
    b[r][c]=0;
    goto nr;
print:
    counter++;
    for(int i = 0; i < 8 ;i++){
        for(int j = 0; j < 8;j++){
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << counter << endl;
    goto backtrack;
}