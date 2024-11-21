#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

const int disks = 3;
const int towers = 3;
const int target_tower = 1;
const int direction = ((disks+target_tower)%2==0) ? 1 : -1;

void printTowers(vector<int>t[towers]){
	for(int i = 0; i < towers;i++){
		cout << (char)(i+'A');
		for(int j = 0; j < t[i].size(); j++){
			cout << "|" << t[i][j];
		}
		cout << endl;
	}
}

int mod(int a, int b){ //Mathematically Correct modulo operation
	return (b+(a%b))%b;
}

int main(){
	int counter = 0;
	vector<int> t[towers]{};
	for(int i = disks-1; i>=0; i--){
		t[0].push_back(i);
	}
	printTowers(t);
	int from_tower = -1 * direction;
	while(t[target_tower].size()<disks){
		from_tower+= direction;
		from_tower = mod(from_tower,towers); //Loop back to numbers from 0-#Towers
		if(t[from_tower].size()==0) continue; 
		int canidate = t[from_tower].back(); //Get the disk on top of current tower.
		if(from_tower==target_tower && disks-canidate==t[from_tower].size()) continue;
		for(int i = 1; i < towers; i++){//Compare current tower to the other ones
			int to_tower = mod(from_tower+(i*direction),towers);
			if((t[to_tower].size()==0)||(canidate <t[to_tower].back())){ //If the comparison tower is empty or the disk can go onto the tower then place is there.
				cout << "Move " << canidate << " from " << (char)(from_tower+'A') << " to " << (char)(to_tower+'A') << endl;
				t[from_tower].pop_back(); //Remove disk from current tower.
				t[to_tower].push_back(canidate); //Add disk to the comparison tower.
				from_tower = to_tower;//Set new form tower to the current to tower
				printTowers(t);
				counter++;
				break;
			}
		}
		usleep(100000);
	}
	cout << "Steps taken: " << counter << endl;
	return 0;
}