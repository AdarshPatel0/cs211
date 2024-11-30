#include <iostream>

using namespace std;

int functionA(int a){
	int c = 1;
	if(a == 0){
		c = a;
	}
	return c;
}

void functionB(int a){
	return;
}

int main(){
	intptr_t aPtr = reinterpret_cast<intptr_t>(functionA);
	intptr_t bPtr = reinterpret_cast<intptr_t>(functionB);
	cout << (bPtr-aPtr) << endl;
	return 0;
}