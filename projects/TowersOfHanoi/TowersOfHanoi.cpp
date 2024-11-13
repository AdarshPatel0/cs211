#include <iostream>
#include <vector>
#include<unistd.h>

using namespace std;

const int disks = 5;
const int towers = 3;
const int target_tower = 1;
const int direction = ((disks)%2==0) ? -1 : 1;

void printTowers(vector<int>t[towers]){
	for(int i = 0; i < towers;i++){
		cout << (char)(i+'A');
		for(int j = 0; j < t[i].size(); j++){
			cout << "|" << t[i][j];
		}
		cout << endl;
	}
}

int mod(int a, int b){ //Methamatically Correct modulo operation
	return (b+(a%b))%b;
}

int main(){
	int counter = 0;
	vector<int> t[towers]{};
	for(int i = disks-1; i>=0; i--){
		t[0].push_back(i);
	}
	printTowers(t);
	int ct = -1 * direction;
	while(t[target_tower].size()<disks){
		ct+= direction;
		ct = mod(ct,towers);
		if(t[ct].size()==0) continue; 
		int smallest_disk = t[ct].back(); //Get the disk on top of current tower.
		if(ct==target_tower && disks-smallest_disk==t[ct].size()) continue;
		int i = 1; //We only want to compare the other towers
		while(i<towers){ //Comparison Loop
			int selected_tower = mod(ct+(i*direction),towers);
			// cout << ct << " " << selected_tower << endl;
			if((t[selected_tower].size()==0)||(smallest_disk <t[selected_tower].back())){ //If the comparison tower is empty or the disk can go onto the tower then place is there.
				cout << "Move " << smallest_disk << " from " << (char)(ct+'A') << " to " << (char)(selected_tower+'A') << endl;
				t[ct].pop_back(); //Remove disk from current tower.
				t[selected_tower].push_back(smallest_disk); //Add disk to the comparison tower.
				ct = selected_tower;
				printTowers(t);
				counter++;
				break;
			}
			i++;
		}
		usleep(500000);
	}
	cout << "Steps taken: " << counter << endl;
	return 0;
}