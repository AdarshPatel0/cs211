#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int counter = 0;
    int q[8]={};
    int c = -1;
    int a[8][5] = {
        {-1},
        {0,-1},
        {0,-1},
        {0,1,2,-1},
        {0,1,3,-1},
        {1,4,-1},
        {2,3,4,-1},
        {3,4,5,6,-1}
    };
nc: c++;
    if(c==8) goto print;
nr: q[c]++;
    if(q[c]==9) goto backtrack;
    for(int i=0;i<c;i++){
        if(q[c]==q[i]) goto nr;
    }
    for(int i = 0;i<5;i++){
        if(a[c][i]==-1) break;
        if(abs(q[c]-q[a[c][i]])==1) goto nr;
    }
    goto nc;
backtrack:
    q[c]=0;
    c--;
    if(c==-1) return 0;
    goto nr;
print:
    cout << " " << q[0] << q[1] << endl;
    cout << q[2] << q[3] << q[4] << q[5] << endl;
    cout << " " << q[6] << q[7] << endl;
    cout << "Solution #" << ++counter << endl << endl;
    goto backtrack;
}