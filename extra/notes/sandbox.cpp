#include <iostream>

using namespace std;

int main(){
	int ** a = new int*[5];
	for(int i = 0; i < 5; i++){
		a[i]= new int[5];
		for(int j = 0; j < 5; j++){
			a[i][j] = i+j;
		}
	}
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			cout << a[i][j] << '\t';
		}
		cout << endl;
	}
}