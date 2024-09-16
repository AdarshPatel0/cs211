#include <iostream>

using namespace std;


int main(){
	int a = 0;
	a:
	cout << "Enter number: ";
	cin >> a;
	if(a==0) goto a;
	cout << a;
	return 0;
}