#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[]){ //This function will check if our solution is good and return a boolean to check if it is true or false
	for(int i=0;i<8;i++){ //This outter loop will itterate through all the columns
		for(int j=0;j<8;j++){ //This inner loop will allow us to compare the other columns to one currently selected by the outter loop
			if(i!=j && q[i]==q[j]){ //This checks for repeating queens on the same row
				return false;
			}
			if(i!=j && abs(i-j)==abs(q[i]-q[j])){ //This checks for and queens diagnoly placed, by checking for the difference in row and column are the same
				return false;
			}
		}
	}
	return true;
}

int main(){
	int numSolutions = 0; //Solution counter
	int q[8]={}; //This array holds 8 integers, with the index representing the column and the value representing the row
	for(int i0=0;i0<8;i0++){ //These nested loops will count up from 00000000 to 77777777 (octal) which are the possible amount of combinations if no two or more queens are on the same column but does allow two or more queens on the same row will will be filted in our 'ok' function
		q[0]=i0;
		for(int i1=0;i1<8;i1++){
			q[1]=i1;
			for(int i2=0;i2<8;i2++){
				q[2]=i2;
				for(int i3=0;i3<8;i3++){
					q[3]=i3;
					for(int i4=0;i4<8;i4++){
						q[4]=i4;
						for(int i5=0;i5<8;i5++){
							q[5]=i5;
							for(int i6=0;i6<8;i6++){
								q[6]=i6;
								for(int i7=0;i7<8;i7++){
									q[7]=i7;
									if(ok(q)){ //If function 'ok' returns true then we will print the board
										cout << "Solution #" << ++numSolutions << ":\n"; //This prints our solution number in the order it was found
										for(int i = 0;i<8;i++){ //Simple nested for loop to print our board
											for(int j = 0;j<8;j++){
												cout << ((j==q[i])?"1 ":"0 ");
											}
											cout << endl;
										}
										cout << endl;
									}
								}
							}
						}						
					}
				}
			}
		}
	}
	return 0; //After counting all possible combinations, we will exit the program
}