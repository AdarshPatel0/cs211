#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	begining:
	int memberCounter[26] = {}; //Holds data of people per team.
	int teamScoreCounter[26] = {}; //Holds data of a teams total score without average.
	int perteam = 0;
	int amountOfTeams = 0;
	double minimumscore = 0;
	char winningTeam = 0;
	string outcome;
	cout << "Enter outcome: ";
	cin >> outcome; //Takes in races outcome as a string.
	for(int i = 0;i<outcome.size();i++){
		if(outcome[i]>'Z'||outcome[i]<'A') goto begining; //If any character in string is not a capital letter, then go back to begining and ask for outcome.
		int team = outcome[i]-'A'; //Get what team this runner is in.
		memberCounter[team]++; //Increment runner count of team.
		teamScoreCounter[team]+=i+1; //Increment total score based off position being checked.
	}
	for(int i = 0; i < outcome.size();i++){
		if (outcome[i]==outcome[0]) perteam++; //Loop through string to find how many characters match first character to find expected runner count per team.
	}
	for(int i = 0; i < 26;i++){
		if (memberCounter[i]!=0 && memberCounter[i]!=perteam) goto begining; //Loop through memberCounter array to make sure all teams only have 0 member (indicating no presence) or match expected member count per team, and restart if mismatched.
		else if(memberCounter[i]!=0){ //Get total amount of teams & get the lowest score and winning team.
			amountOfTeams++; //
			double averagescore = (double)teamScoreCounter[i]/perteam;
			if (averagescore < minimumscore || minimumscore == 0){
				minimumscore = averagescore;
				winningTeam = i+'A'; //Index(i) represents team name
			}
		}
	}
	cout << "There are " << amountOfTeams << " teams.\n" << endl; //Print results.
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