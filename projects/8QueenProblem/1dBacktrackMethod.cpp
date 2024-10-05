#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int numSolutions = 0; //Solution counter
    int c = -1; //We initialize at col -1 since we immediately go to col 0
    int q[8]={}; //This array holds 8 integers, with the index representing the column and the value representing the row
nc:
    c++; //This goes to the next column
    if(c==8){
        goto print; //There is not column '8', and the only way for this condition to be possible is if all queens have been places successfuly which means a solution hase been found and we can print it.
    };
    q[c]=-1; //We set the row to -1 since we will immediately increment to 0
nr:
    q[c] = q[c]+1; //This goes to the next row
    if(q[c]==8){ //There is not row '8', and the only way for this condition to be possible is if there are no more ways to place a queens, and there fore be must backtrack to find another route.
        goto backtrack;
    }
    for(int i = 0; i<c; i++){ //This loop will itterate through the previous columns
        if(q[i]==q[c]){ //This checks if another queens is on this row
            goto nr;
        }
        if(c-i == abs(q[c]-q[i])){ //This checks for and queens diagnoly placed, by checking for the difference in row and column are the same
            goto nr;
        }
    }
    goto nc; //If all the conditions above are found to be false, that means we have found a row to put a queen on our current column and therefore to can go to the next column
backtrack:
    c--; //This goes back one column
    if(c==-1){ //This checks if there are no more ways to backtrack, the only way for this to be possible is if all options are exahusted and exits if it is true
        return 0;
    }
    goto nr; //Not that we are on out previous column, we have to find a another row that we can a queen on
print:
    cout << "Solution #" << ++numSolutions << ":\n"; //This prints our solution number in the order it was found.
	for(int i = 0;i<8;i++){ //Simple nested for loop to print our board
		for(int j = 0;j<8;j++){
			cout << ((j==q[i])?"1 ":"0 ");
		}
		cout << endl;
	}
    cout << endl;
    goto backtrack; //We have to back track to see if more solutions are possible
}