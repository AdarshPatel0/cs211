#include<iostream>
#include<cmath>
using namespace std;

bool test(int cross[], int curr_box) {
	static int checkList[8][5] = {
		{-1},
		{0,-1},
		{1,-1},
		{0,1,2,-1},
		{1,2,3,-1},
		{2,4,-1},
		{0,3,4,-1},
		{3,4,5,6,-1},
	};
	for(int i=0;i<curr_box;i++){ //There cannot be repeating values, this loop will chck if the value for the box we are currently on is repeated, and will go to the next possible value if the current value has already been used
		if(cross[curr_box]==cross[i]) return false;
	}
	for(int i = 0;i<5;i++){ //This loop will be used to compare adjacent boxes using the map 'a'
    	if(checkList[curr_box][i]==-1) break; //This will make us stop checking for adjecnt boxes since there are none left when we reach -1
    	if(abs(cross[curr_box]-cross[checkList[curr_box][i]])==1) return false; //This will check if the absolute difference of the value of our current box and the selected adjacent box is 1, if it is then we go to the next possible value for the box
	}
	return true;
}

void print(int cross[]) {
  // everytime this function is called, count will not reset to 0 since it is static
  // static means the variable is allocated only once during the runtime of the program
	static int count = 0;
	cout << " Solution number: " << ++count << endl;
	cout << " " << cross[1] << cross[2] << endl;
	cout << cross[0] << cross[3] << cross[4] << cross[5] << endl;
	cout << " " << cross[6] << cross[7] << endl << endl;
	return;
}

int main() {
   int q[8] = {};   // Initialize the array to 0.
   // Start in the 1st value, 1st box
   int c = 0;
   q[c] = 1;
   while (c >= 0) { // this loop ends when you backtrack from the first box like when c is 1
      // Move to the next box
	  c++;
      // If you have passed the last box,
         // Call the print function and backtrack
	if(c==8){
		print(q);
	}
      // Otherwise, initialize value to one before the first possible value
	  q[c] = 0;
      while (q[c] >= 0) {
         // Move to the next value
		 q[c]++;
         // If you have passed the end of the box, backtrack
		 if(q[c]==9){
			c--;
		 }
		 else if(test(q,c)){
			break;
		 }
         // Else If the ok function it returns true, break out of this loop to move on from the outer loop
      }
   }
   return 0;
}
