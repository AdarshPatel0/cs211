#include <iostream>

using namespace std;

const int n = 10;

int chache[n] = {0};

int fibonacci(int n){
	if(n==1 || n==0) return 1;
	if (chache[n]!=0) return chache[n];
	chache[n] = fibonacci(n-1) + fibonacci(n-2);
	return chache[n];
}

int main(){
	cout << fibonacci(n);
	return 0;
}