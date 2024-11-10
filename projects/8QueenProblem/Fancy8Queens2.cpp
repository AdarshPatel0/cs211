#include <cmath>
#include <iostream>
using namespace std;

wchar_t bq[5][7] = { //We use wchar instead since char does not support the size needed for the block character
	{' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', L'\u2588', ' ', L'\u2588', ' ', L'\u2588', ' '},
	{' ', L'\u2588', L'\u2588', L'\u2588', L'\u2588', L'\u2588', ' '},
	{' ', L'\u2588', L'\u2588', L'\u2588', L'\u2588', L'\u2588', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' '},
};
wchar_t wq[5][7] = {{L'\u2588', L'\u2588', L'\u2588', L'\u2588', L'\u2588', L'\u2588', L'\u2588'},
				 {L'\u2588', ' ', L'\u2588', ' ', L'\u2588', ' ', L'\u2588'},
				 {L'\u2588', ' ', ' ', ' ', ' ', ' ', L'\u2588'},
				 {L'\u2588', ' ', ' ', ' ', ' ', ' ', L'\u2588'},
				 {L'\u2588', L'\u2588', L'\u2588', L'\u2588', L'\u2588', L'\u2588', L'\u2588'}};
wchar_t bb[5][7] = {{L'\u2588', L'\u2588', L'\u2588', L'\u2588', L'\u2588', L'\u2588', L'\u2588'},
				 {L'\u2588', L'\u2588', L'\u2588', L'\u2588', L'\u2588', L'\u2588', L'\u2588'},
				 {L'\u2588', L'\u2588', L'\u2588', L'\u2588', L'\u2588', L'\u2588', L'\u2588'},
				 {L'\u2588', L'\u2588', L'\u2588', L'\u2588', L'\u2588', L'\u2588', L'\u2588'},
				 {L'\u2588', L'\u2588', L'\u2588', L'\u2588', L'\u2588', L'\u2588', L'\u2588'}};
wchar_t wb[5][7] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '},
				 {' ', ' ', ' ', ' ', ' ', ' ', ' '},
				 {' ', ' ', ' ', ' ', ' ', ' ', ' '},
				 {' ', ' ', ' ', ' ', ' ', ' ', ' '},
				 {' ', ' ', ' ', ' ', ' ', ' ', ' '}};
typedef wchar_t box[5][7];
box *board[8][8]{};

bool test(int board[], int c) {
  for (int i = 0; i < c;
	   i++) { // This loop will itterate through the previous columns
	if (board[i] == board[c]) { // This checks if another queens is on this row
	  return false;
	}
	if (c - i ==
		abs(board[c] - board[i])) { // This checks for and queens diagnoly
									// placed, by checking for the difference in
									// row and column are the same
	  return false;
	}
  }
  return true;
}

void print(int q[]) {
  // everytime this function is called, count will not reset to 0 since it is
  // static static means the variable is allocated only once during the runtime
  // of the program
  static int count = 0;
  cout << "Solution number: " << ++count << endl;
//   for (int i = 0; i < 8; i++) { // Simple nested for loop to print our board
// 	for (int j = 0; j < 8; j++) {
// 	  cout << ((j == board[i]) ? "1 " : "0 ");
// 	}
// 	cout << endl;
//   }
	for(int i = 0; i < 8; i++){ //Only change queen boxes on board
		if((i+q[i])%2==0){
			board[i][q[i]] = &wq;
		}
		else {
			board[i][q[i]] = &bq;
		}
	}

	cout << '+';
	for(int i = 0; i < 56; i++){
	cout << '-';
	}
	cout << '+';
	cout << endl;

	for(int i = 0; i < 8; i++){
		for(int k = 0; k < 5; k++){
			cout << '|';
			for(int j = 0; j < 8; j++){
				for(int l = 0; l < 7; l++){
					wcout << (*board[i][j])[k][l]; //wcout is needed to print wchar
				}
			}
			cout << '|' << endl;
		}
	}
	cout << '+';
	for(int i = 0; i < 56; i++){
	cout << '-';
	}
	cout << '+';
	cout << endl;

	for(int i = 0; i < 8; i++){ //Revert change to regular empty checker board pattern
		if((i+q[i])%2==0){
			board[i][q[i]] = &bb;
		}
		else {
			board[i][q[i]] = &wb;
		}
	}
  cout << endl;
  return;
}

int main() {
	setlocale(LC_ALL, "en_US.UTF-8"); //This is needed for Unix/Linux systems
	for(int i = 0; i < 8; i++){ //Fill in Board with checkermark patterns
		for(int j = 0; j < 8; j++){
			if((i+j)%2==0){
				board[i][j] = &bb;
			}
			else {
				board[i][j] = &wb;
			}
		}
	}
  int q[8] = {}; // Initialize the array to 0.
  // Start in the 1st value, 1st box
  int c = 0;
  q[c] = -1;
  while (c >= 0) { // this loop ends when you backtrack from the first box like
				   // when c is 1
				   // If you have passed the last box,
				   // Call the print function and backtrack
	if (c == 8) {
	  print(q);
	}
	// Otherwise, initialize value to one before the first possible value
	q[c] = -1;
	while (q[c] >= -1) {
	  // Move to the next value
	  q[c]++;
	  // If you have passed the end of the box, backtrack
	  if (q[c] == 8) {
		c--;
	  } else if (test(q, c)) {
		break;
	  }
	  // Else If the ok function it returns true, break out of this loop to move
	  // on from the outer loop
	}
	if (c == -1)
	  break;
	// Move to the next box
	c++;
  }
  return 0;
}
