#include <iostream>

using namespace std;

int main(){
	int counter = 0;
	int q[8]={},c=0;
	q[0]=0;
nc: c++;
	if(c==8) goto print;
	cout << "Checking on column " << c << endl;
	q[c] = -1;
	goto nr;
nr: q[c]++;
	cout << "Checking column "<< c << " with value of " << q[c] << endl;
	if(q[c]==8){
		cout << "Exceeded rows left!" << endl;
		goto backtrack;
	}
	for(int i = c-1;i>=0;i--){
		if(q[i]==q[c]) goto nr;
	}
	goto nc;
backtrack: c--;
	if(c==-1) return 0;
	q[c]=-1;
	goto nc;
print:
	counter++;
	for(int i = 0;i<8;i++){
		for(int j = 0;j<8;j++){
			cout << ((j==q[i])?"1 ":"0 ");
		}
		cout << endl;
	}
	cout << "Solution " << counter << endl;
	cout << endl;
	goto backtrack;
}