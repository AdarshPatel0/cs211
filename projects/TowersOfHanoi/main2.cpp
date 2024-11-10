#include <iostream>
#include <vector>
#include<unistd.h>

using namespace std;

const int disks = 3;
const int towers = 4;
const int target_tower = 2;

void printTowers(vector<int>t[towers]){
	for(int i = 0; i < towers;i++){
		cout << (char)(i+'a');
		for(int j = 0; j < t[i].size(); j++){
			cout << "|" << t[i][j];
		}
		cout << endl;
	}
}

int main(){
    int targetkeep = disks-1;
	vector<int> t[towers]{};
	for(int i = disks-1; i>=0; i--){
		t[0].push_back(i);
	}
	printTowers(t);
	int ct = -1;
	while(t[target_tower].size()<disks){
		ct++;
		ct = ct%towers;
		if(t[ct].size()==0) continue; 
		int smallest_disk = t[ct].back(); //Get the disk on top of current tower.
		if(ct==target_tower && disks-smallest_disk==t[ct].size()) continue;
		int i = 1; //We only want to compare the other towers
		while(i<towers){ //Comparison Loop
			if((t[(ct+i)%towers].size()==0)||(smallest_disk <t[(ct+i)%towers].back())){ //If the comparison tower is empty or the disk can go onto the tower then place is there.
				cout << "Move " << smallest_disk << " from " << (char)(ct+'A') << " to " << (char)((ct+i)%towers+'A') << endl;
				t[ct].pop_back(); //Remove disk from current tower.
				t[(ct+i)%towers].push_back(smallest_disk); //Add disk to the comparison tower.
                ct = (ct+i)%towers;
				printTowers(t);
				break;
			}
			i++;
		}
		usleep(500000);
	}
	return 0;
}