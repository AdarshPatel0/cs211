#include <iostream>
#include <cmath>

using namespace std;

void print(int q[], int &counter){
	cout << "Solution #" << ++counter << endl;
	cout << " " << q[0] << q[1] << endl;
	cout << q[2] << q[3] << q[4] << q[5] << endl;
	cout << " " << q[6] << q[7] << endl << endl;
}

int main(){
	int counter = 0; //Solution counter
	int q[8]={}; //This is a representation of our cross with 8 boxes
	int c = 0; //This will count which box we will be on
	bool fail = false;
	int a[8][5] = { //This is a map of what indecies need to be checked when we are checking for difference of adjacent elements. a[x][y]: x will represent a box, y will represent a box that is adjecent to x, -1 represents the end of adjecent boxes 
		{-1},
		{0,-1},
		{0,-1},
		{0,1,2,-1},
		{0,1,3,-1},
		{1,4,-1},
		{2,3,4,-1},
		{3,4,5,6,-1}
	};
	while(c>-1){
		while(q[c]<9){
			fail = false;
			q[c]++;
		    for(int i=0;i<c;i++){ //There cannot be repeating values, this loop will chck if the value for the box we are currently on is repeated, and will go to the next possible value if the current value has already been used
    			if(q[c]==q[i]) fail = true;
    		}
			for(int i = 0;i<5;i++){ //This loop will be used to compare adjacent boxes using the map 'a'
        		if(a[c][i]==-1) break; //This will make us stop checking for adjecnt boxes since there are none left when we reach -1
        		if(abs(q[c]-q[a[c][i]])==1) fail = true; //This will check if the absolute difference of the value of our current box and the selected adjacent box is 1, if it is then we go to the next possible value for the box
    		}
			if(fail) continue;
			break;
		}
		if(q[c]>8){
			q[c]=0;
			c--;
			continue;
		}
		c++;
		if(c==8){
			print(q, counter);
			c=6;
		}
	}
	return 0;
}