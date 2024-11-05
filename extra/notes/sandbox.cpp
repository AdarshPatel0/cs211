#include <iostream>

using namespace std;

bool ok(int q[], int c){
	for(int i = 0; i<c; i++){
		if(q[i]==q[c]) return false;
		if(abs(q[c]-q[i])==c-i) return false;
	}
	return true;
};


int main(){
	int q[8]= {7,3,0,2,5,1,6,4}; //This will pass
	int r[8]= {7,3,0,2,5,4,6,4}; //This will faill since it fails the row test
	int s[8]= {3,7,0,2,6,1,5,4}; // This will fail since it fails the diagnol test
	cout << ok(q,7) << endl;//1
	cout << ok(r,7) << endl;//0
	cout << ok(s,7) << endl;//0

	return 0;
}