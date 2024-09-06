#include <iostream>
using namespace std;

int main() {
	string numA;
	string numB;
	string sum;
	int maxLength;
	//Get our numbers.
	cout << "First integer (up to 100 digits):";
	cin >> numA;
	cout << "Second integer (up to 100 digits):";
	cin >> numB;
	//Fail if input exceeds 100 digits.
	if (numA.length() > 100 || numB.length() > 100){
		cout << "Too many digits! Exiting." << endl;
		exit(1);
	}
	//Find out how many total bases are going to be calculated and add zeros even out the digit count on the number with the smallest base.
	if (numA.length() >= numB.length()){
		maxLength = numA.length();
		numB.insert(0,numA.length()-numB.length(),'0');
	}
	else if (numA.length() <= numB.length()){
		maxLength = numB.length();
		numA.insert(0,numB.length()-numA.length(),'0');
	}
	bool carryOver = false;
	int i = maxLength-1;
	for(int i = maxLength-1; i>=0;i--){
		int baseSum = numA[i] + numB[i] - (2*'0') + carryOver;
		carryOver = false;
		if (baseSum > 9){
			carryOver = true;
			baseSum-=10;
		}
		sum.insert(0,1,baseSum+'0');
	}
	if(carryOver == true) sum.insert(0,1,'1');
	cout << sum << endl; 
	return 0;
}