#include <iostream>

using namespace std;

int mp[3][3] = {
	{0,2,1},
	{0, 2, 1},
	{1, 2, 0}
	};
int wp[3][3] = {
	{2, 1, 0},
	{0, 1, 2},
	{2, 0, 1}
	};

bool ok(int q[], int c) {
	for (int i = 0; i < c; i++) { //'i' is the man that we are comparing to the currently selected man.
	if (q[c] == q[i])
		return false; // Fail if repeats.
	//If comparison mans preference for his woman is less than his preference of the current mans woman AND vice versa for the women, then fail.
	if (mp[i][q[i]] < mp[i][q[c]] && wp[q[c]][c] < wp[q[c]][i])
		return false;
	//If current mans preference for his woman is less than his preference of the comparison mans woman AND vice versa for the women, then fail.
	if (mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i])
		return false;
	}
	//If there are no fails, then say that this match is ok.
	return true;
}

void print(int q[]) {
	static int counter = 0;
	cout << "Solution #" << ++counter << endl;
	cout << "Men\tWomen" << endl;
	for (int i = 0; i < 3; i++) {
	cout << i << "\t" << q[i] << endl;
	}
}

int main() {
	int q[3] = {}; // Array that holds matches whih index representing men and value representing women.
	int c = 0; // Start at the first man.
	q[c] = 0;  // Match current man with first woman.
	while (c >= 0) { //Run this while there are enough place to back track to.
	c++;//Go to next man.
	if (c == 3) { //If we run out of men to match, then print and go back since we have a proper matching.
		print(q);
		c--;
	} else {//Select no women so that when we advance to the next one, we dont skip the first one.
		q[c] = -1;
	}
	while (true) { //Continualy try to find a match.
		q[c]++; //Go to next woman.
		if (q[c] == 3) { //If we run out of women to match, we backtrack.
		c--;
		}
		else if (ok(q, c)) //If the current match is valid, then we can stop choosing the next woman and leave the current mans match value to the current woman.
		break;
	}
	}
	return 0;
}