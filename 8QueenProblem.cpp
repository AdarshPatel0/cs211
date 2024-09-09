#include <iostream>
#include <vector>

using namespace std;

void print(int number[8]){
	for(int i=0;i<8;i++){
		cout << number[i] << "|";
	}
	cout << endl;
}

void add(int A[8], int B[8], int C[8]){
	for(int i=7;i>=0;i--){
		int sum = A[i]+B[i]+C[i];
		if(sum>=64){
			if(i-1<0){
				C[0]=-1;
			}
			else {
				C[i]=sum-64;
				C[i-1]++;
			}
		}
		else {
			C[i]=sum;
		}
	}
}

void updateArray(int A[], int B[]){
	for(int i=0; i <8; i++){
		A[i] = B[i];
	}
}


int main(){
	int currentConfig[8] = {};
	currentConfig[7]=0;
	int one[8]={};
	one[7]=1;
	long count = 0;
	vector<int> noOverlaps;
	while (currentConfig[0]!=-1){
		int newConfig[8]={};
		add(currentConfig, one, newConfig);
		updateArray(currentConfig, newConfig);
		count++;
	}
	cout << count << endl;
	return 0;
}