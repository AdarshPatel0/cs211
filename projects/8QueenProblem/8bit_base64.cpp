#include <iostream>

using namespace std;

void print(int number[8]){
	for(int i=0;i<8;i++){
		cout << number[i] << "|";
	}
	cout << endl;
}

void add(int A[8], int B[8], int C[8]){
	for(int i=7;i>=0;i--){
		int sum = A[i]+B[i];
		if(sum>=64){
			if(i-1<0){
				C[0]=-1;
			}
			else {
				C[i]=sum-64;
				A[i-1]++;
			}
		}
		else {
			C[i]=sum;
		}
	}
}

int main(){
	int A[8] = {0,0,0,0,0,0,0,1};
	int B[8] = {0,0,0,0,0,0,0,0};
	int C[8]= {};
	print(A);
	print(B);
	add(A, B, C);
	print(C);
	return 0;
}