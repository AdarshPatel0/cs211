#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int counter = 0; //Solution counter
    int q[8]={}; //This is a representation of our cross with 8 boxes
    int c = -1; //This will count which box we will be on
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
nc: c++; //This will go to the next box
    if(c==8) goto print; //The highest index is 7, for it to be would mean that all boxes were sucesssfully populated which gives us a solution that we can print
nr: q[c]++; //This will increase the value of a box by one
    if(q[c]==9) goto backtrack; //There are only 8 possible values (1-8) if we are checking if we can put 9, that means that there are no more options, and therefore we must back track
    for(int i=0;i<c;i++){ //There cannot be repeating values, this loop will chck if the value for the box we are currently on is repeated, and will go to the next possible value if the current value has already been used
        if(q[c]==q[i]) goto nr;
    }
    for(int i = 0;i<5;i++){ //This loop will be used to compare adjacent boxes using the map 'a'
        if(a[c][i]==-1) break; //This will make us stop checking for adjecnt boxes since there are none left when we reach -1
        if(abs(q[c]-q[a[c][i]])==1) goto nr; //This will check if the absolute difference of the value of our current box and the selected adjacent box is 1, if it is then we go to the next possible value for the box
    }
    goto nc; //This the currently selected value for our currently selected box passes our tests, that means it is valid, and we can go to the next box
backtrack:
    q[c]=0; //This resets the current box before going back
    c--; //This will make us go back to the previous box
    if(c==-1) return 0; //If we go back to box -1 which does not exist, that means that all solutions have been found and we can exit the program
    goto nr; //This will increment to the next value to see if we can find a solution
print:
    cout << "Solution #" << ++counter << endl;
    cout << " " << q[0] << q[1] << endl;
    cout << q[2] << q[3] << q[4] << q[5] << endl;
    cout << " " << q[6] << q[7] << endl << endl;
    goto backtrack; //We need to see if more solutions are available, therefore we will go back to find another solution
}