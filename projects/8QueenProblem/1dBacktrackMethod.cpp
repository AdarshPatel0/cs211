#include <iostream>
using namespace std;
int main(){
    int solutionc = 0;
    int c = -1;
    int q[8]={};
nc:
    c++;
    if(c==8){
        goto print;
    };
    q[c]=-1;
nr:
    q[c] = q[c]+1;
    if(q[c]==8){
        goto backtrack;
    }
    for(int i = 0; i<c; i++){
        if(q[i]==q[c]){
            goto nr;
        }
        if((c-i == q[c]-q[i])||(c-i == -(q[c]-q[i]))){
            goto nr;
        }
    }
    goto nc;
backtrack:
    c--;
    if(c==-1){
        return 0;
    }
    goto nr;
print:
    solutionc++;
	for(int i = 0;i<8;i++){
		for(int j = 0;j<8;j++){
			cout << ((j==q[i])?"1 ":"0 ");
		}
		cout << endl;
	}
    cout << solutionc << endl << endl;
    goto backtrack;
}