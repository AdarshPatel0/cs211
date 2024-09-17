#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	begining:
	int memberCounter[26] = {};
	int teamScoreCounter[26] = {};
	int perteam = 0;
	string outcome;
	cout << "Enter outcome: ";
	cin >> outcome;
	for(int i = 0;i<outcome.size();i++){
		if(outcome[i]>'Z'||outcome[i]<'A') goto begining;
		int team = outcome[i]-'A';
		memberCounter[team]++;
		teamScoreCounter[team]+=i+1;
	}
	for(int i = 0; i < 26;i++){
		if(memberCounter[i] != 0 && perteam == 0);
	}
	return 0;
}