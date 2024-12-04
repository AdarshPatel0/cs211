#include <iostream>

using namespace std;

int ** createArray(int size){
	int **a = new int*[size];
	for(int i = 0; i<size; i++){
		a[i] = new int[size];
		for(int j = 0; j < size ; j++){
			a[i][j] = i+j;
		}
	}
	return a;
};

void print(int ** a,int size){
	for(int i = 0; i<size; i++){
		for(int j = 0; j < size; j++){
			cout << '\t' << a[i][j];
		}
		cout << endl;
	}
}

void deleteArray(int ** a,int size){
	for(int i = 0; i<size; i++){
		delete a[i];
	}
	delete [] a;
}

int main(){
	int **a = createArray(5);
	deleteArray(a,5);
	a = createArray(8);
	print(a,8);
	deleteArray(a,8);
	return 0;
}