// Find the first perfect square whose last two digits are both odd
#include <iostream>

using namespace std;

int main() {
  int current_int = 0;
  while (true) {
	int current_square = current_int * current_int; //Get the square of our base
	if (current_square < 10){ //If the current square is less than 10, then there are not enough digits to check.
		current_int++; //As such we go to the next base
		continue;
	}
	if ((current_square % 10)% 2 == 1 && (((current_square / 10) % 10)%2 == 1)){ //Check if last two digits are odd
		cout << current_int << " To the power of 2 is " << current_square << endl; //If true then print out base and perfect square
		cout << "BUT!! if we take "<< current_square << " and dvide it by " << current_int << " we get " << (double)current_square/current_int << " ,which is not a perfect square" << endl;
		break;
	}
	else {
		current_int++; // Continue to check the next base
	}
  }
  return 0;
}

// No such number exists and as such, what happens is that the integer 'curent_square' overflows when calculated
// and we are left with a false perfect sqaure of 131073 which is NOT 65537^2.
// 65537^2 is 4,295,098,369, which goes over the 32bit integer limit of 4,294,967,296
// This is how we can calculate our false square:
//-4,294,967,296 + 4,295,098,369 = 131,073