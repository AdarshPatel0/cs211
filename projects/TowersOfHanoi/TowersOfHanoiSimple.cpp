#include  <iostream>
#include <vector>

using namespace std;

const int disks = 4; //These values will remain the same throught the program, so we use const
const int NextTower = (disks%2==0)?2:1; //These ternary operations will allow us to set the direction of the algorithm
const int OtherTower = (disks%2==0)?1:2;

static int from = 0, to = (disks%2==0)?2:1, canidate = 1, moves = 0; //These Values will be chaning so we use static

void printTowers(vector<int>t[3]){
	for(int i = 0; i < 3;i++){//Loop throught the array of vectors
		cout << (char)(i+'A'); //Print the towers name
		for(int j = 0; j < t[i].size(); j++){ //Loop throught the vector of disks
			if(t[i][j] != disks+1) cout << "|" << t[i][j]; //Onlt print the disk if it is not a padded value
		}
		cout << endl;
	}
}

int main(){	
	vector <int> towers[3];
	for(int i = 0; i < 3; i++){ //Pad the bottom of the towers will values that are one bigger then the biggest disk value
		towers[i].push_back(disks+1);
	}
	for(int i = disks; i > 0; i--){ //Populate tower A with disks
		towers[0].push_back(i);
	}
	printTowers(towers);
	while(towers[1].size()<disks+1){
		moves++; //Increase move counter
		towers[to].push_back(canidate); //Put the canidate on the to tower
		towers[from].pop_back(); //Remove the canidate from the from tower

		cout << "Step " << moves << ": Move " << canidate << " from " << char(from+'A') << " to " << char(to+'A') << endl;

		printTowers(towers);
		if(towers[(to+NextTower)%3].back() > towers[(to+OtherTower)%3].back()){ //If the top of the next tower is bigger then the top of the other tower, then set the from tower to the other tower since it has a smaller disk on top
			from = (to+OtherTower)%3;
		}
		else { //If the disk on top of the other tower is bigger, then set the new tower to move from to the next tower
			from = (to+NextTower)%3;
		}

		canidate = towers[from].back(); //Get the canidate from our new from tower
		if(canidate > towers[(from+NextTower)%3].back()){ //See if we can not put the canidate on the next tower
			to = (from+OtherTower)%3; //If we cannot then put it on the other tower
		}
		else{
			to = (from+NextTower)%3; //If we can then put it on the next tower
		}
	}
	return 0;
}