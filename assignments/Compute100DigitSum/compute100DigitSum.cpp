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
	//Terminate if input exceeds 100 digits.
	if (numA.length() > 100 || numB.length() > 100){
		cout << "Too many digits! Exiting." << endl;
		exit(1);
	}
	//Find out how many total bases are going to be calculated and add zeros even out the digit count on the number with the smallest amount of base.
	if (numA.length() >= numB.length()){
		maxLength = numA.length();
		numB.insert(0,numA.length()-numB.length(),'0');
	}
	else if (numA.length() <= numB.length()){
		maxLength = numB.length();
		numA.insert(0,numB.length()-numA.length(),'0');
	}
	bool carryOver = false; //Saves data out of loop if carry over is needed
	int i = maxLength-1;
	int baseSum;
	for(int i = maxLength-1; i>=0;i--){ 
		baseSum = numA[i] + numB[i] - (2*'0') + carryOver; //Add digits of the same base including carry over amount. (The digits are character types and are converted into integer types by subtracting their ASCII value.)
		carryOver = false; //Cerry over has been added, so it is set to false/0.
		if (baseSum > 9){ //If base exceeds 9 then it must be carried over by removing the extra base and storing it in our carry over variable.
			carryOver = true;
			baseSum-=10;
		}
		sum.insert(0,1,baseSum+'0'); //Inserts the sum of the base into the front of the string. (baseSum has to be converted into a character by adding the ASCII value for numbers.)
	}
	if(carryOver == true) sum.insert(0,1,'1'); //If a extra base is left over, we will add that too.
	cout << sum << endl; //Prints our sum as a string
	return 0;
}