#include <iostream>

using namespace std;
int mod(int a, int b){
	int v = (b+(a%b))%b;
	return v;
}
int main(){
	cout << mod(-2,3) << endl;
	return 0;
}