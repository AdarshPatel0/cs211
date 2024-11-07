#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> t[3];
	t[0] = {2,1,0};
	int ct = -1;
	while(true){
		ct++;
		if(ct == 3) ct = 0;
		if(t[ct].size()==0) continue;
		int smallest_disk = t[ct].back();
		cout << smallest_disk << endl;
		int i = ct;
		while (true) {
			i++;
			if(i==3) i=0;
			if(i == ct) continue;
			if(t[i].size()==0) break;
			if(smallest_disk<t[i].back()) break;
		}
		t[ct].pop_back();
		t[i].push_back(smallest_disk);
		if(t[1].size()==3) break;
		if(i==0) ct=0;
	}
	return 0;
}