#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	begining:
	int memberCounter[26] = {};
	int teamScoreCounter[26] = {};
	int perteam = 0;
	int amountOfTeams = 0;
	double minimumscore = 0;
	char winningTeam = 0;
	string outcome;
	cout << "Enter outcome: ";
	cin >> outcome;
	for(int i = 0;i<outcome.size();i++){
		if(outcome[i]>'Z'||outcome[i]<'A') goto begining;
		int team = outcome[i]-'A';
		memberCounter[team]++;
		teamScoreCounter[team]+=i+1;
	}
	for(int i = 0; i < outcome.size();i++){
		if (outcome[i]==outcome[0]) perteam++;
	}
	for(int i = 0; i < 26;i++){
		if (memberCounter[i]!=0 && memberCounter[i]!=perteam) goto begining;
		else if(memberCounter[i]!=0){
			amountOfTeams++;
			double averagescore = (double)teamScoreCounter[i]/perteam;
			if (averagescore < minimumscore || minimumscore == 0){
				minimumscore = averagescore;
				winningTeam = i+'A';
			}
		}
	}
	cout << "There are " << amountOfTeams << " teams.\n" << endl;
	cout << "Each team has " << perteam << " runners.\n" << endl;
	printf("Team\tScore\t\n");
	for(int i = 0; i < 26; i++){
		if(teamScoreCounter[i]!=0){
			printf("%c\t%.2f\n",i+'A',(double)teamScoreCounter[i]/perteam);
		}
	}
	cout << "The winning team is team " << winningTeam << " with a score of " << minimumscore << endl;
	return 0;
}