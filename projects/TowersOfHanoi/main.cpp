#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> t[3]{};
	t[0] = {2,1,0};
	int ct = -1;
	while(t[1].size()<3){
		ct++;
		if(ct == 3) ct = 0;
		if(t[ct].size()==0) continue;
		int smallest_disk = t[ct].back(); //Get the disk on top of current tower.
		if(ct==1 && smallest_disk==2) continue; //If the smallest disk is the largest disk in the final position, then skip the current tower and go to the next tower.
		int i = 1; //We only want to compare the other two towers
		while(i<3){ //Comparison Loop
			if((t[(ct+i)%3].size()==0)||(smallest_disk <t[(ct+i)%3].back())){ //If the comparison tower is empty or the disk can go onto the tower then place is there.
				cout << "Move " << smallest_disk << " from " << (char)(ct+'A') << " to " << (char)((ct+i)%3+'A') << endl;
				t[ct].pop_back(); //Remove disk from current tower.
				t[(ct+i)%3].push_back(smallest_disk); //Add disk to the comparison tower.
				if((ct+i)%3==0) ct = 0; //If we moved the disk back to the first tower, then skip checking the current tower and check if the other discs in different towers can be moved
				else ct = -1;
				break;
			}
			i++;
		}
	}
	return 0;
}