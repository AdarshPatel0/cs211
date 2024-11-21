#include  <iostream>
#include <vector>

using namespace std;

void printTowers(vector<int>t[3]){
	for(int i = 0; i < 3;i++){
		cout << (char)(i+'A');
		for(int j = 0; j < t[i].size(); j++){
			cout << "|" << t[i][j];
		}
		cout << endl;
	}
}

int main(){
	int disks = 3;
	int from = 0, to = (disks%2==0)?2:1, canidate = 1, moves = 0;
	
	vector <int> towers[3];
	for(int i = 0; i < 3; i++){
		towers[i].push_back(disks+1);
	}
	for(int i = disks; i > 0; i--){
		towers[0].push_back(i);
	}
	printTowers(towers);
	while(towers[1].size()<disks+1){
		moves++;
		towers[to].push_back(canidate);
		towers[from].pop_back();
		cout << "Move " << canidate << " from " << char(from+'A') << " to " << char(to+'A') << endl;
		printTowers(towers);
		if(towers[(to+1)%3].back() > towers[(to+2)%3].back()){
			from = (to+2)%3;
		}
		else {
			from = (to+1)%3;
		}
		canidate = towers[from].back();
		if(canidate > towers[(from+1)%3].back()){
			to = (from+2)%3;
		}
		else{
			to = (from+1)%3;
		}
	}
	return 0;
}