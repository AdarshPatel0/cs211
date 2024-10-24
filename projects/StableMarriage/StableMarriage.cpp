#include<iostream>
using namespace std;
// pro for proposals
bool ok(int pro[], int c) { // Finish this code
	static int mp[3][3] =
			{ { 0,2,1 },  	 // Man#0's preferences
				{ 0,2,1 },	// Man#1's preferences
				{ 1,2,0 } };	// Man#2's preferences

	static int wp[3][3] =
			{ { 2,1,0 },		// Woman#0's preferences
				{ 0,1,2 },	// Woman#1's preferences
				{ 2,0,1 } };	 // Woman#2's preferences

	/*Similar to 1D Queens, use a loop to check the array.
	  Inside the loop we chould check for 3 conditions
	  First condition checks is the same women is married to two different man *hint we need to check if two things are equal*
	  Second condition checks if (Man_i) and (Man_c's wife) both like each other more than their own spouse
	  Third condition checks if (Man_c) and (Man_i's wife) both like each other more than their own spouse

	  mp[i][j] tells you how much Man_i likes Woman_j. (0 = favorite; 2 = least favorite)
	  wp[i][j] tells you how much Woman_i likes Man_j.

	  mp[i][pro[i]] tells you how much Man_i likes his own wife.
	  mp[i][pro[c]] tells you how much Man_i likes Man_c's wife.
	  wp[pro[i]][i] tells you how much Man_i's wife likes Man_i.
	  wp[pro[i]][c] tells you how much Man_i's wife likes Man_c.
	  If mp[i][pro[c]] < mp[i][pro[i]], it means that Man_i likes Man_c's wife more than his own wife
	*/

	//if we pass the loop, what do we return?
	for (int i = 0; i < c; i++) { //'i' is the man that we are comparing to the currently selected man.
	if (pro[c] == pro[i])
		return false; // Fail if repeats.
	//If comparison mans preference for his woman is less than his preference of the current mans woman AND vice versa for the women, then fail.
	if (mp[i][pro[i]] < mp[i][pro[c]] && wp[pro[c]][c] < wp[pro[c]][i])
		return false;
	//If current mans preference for his woman is less than his preference of the comparison mans woman AND vice versa for the women, then fail.
	if (mp[c][pro[i]] < mp[c][pro[c]] && wp[pro[i]][c] < wp[pro[i]][i])
		return false;
	}
	//If there are no fails, then say that this match is ok.
	return true;
}

void print(int q[]) {
	static int solution = 0;
	cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
	//Finish this print function such that you print the index (man) and value (woman) with a tab inbetween
	for (int i = 0; i < 3; i++) {
		cout << i << "\t" << q[i] << endl;
	}
}


int main() {
	int q[3]={};
	int c = 0;
	q[c]=0;
	while(c>=0){
		c++;
		if(c==3){
			print(q);
			c--;
		}
		else {
			q[c]=-1;
		}
		while(c>=0){
			q[c]++;
			if(q[c]==3){
				c--;
			}
			else if(ok(q, c)){
				break;
			}
		}
	}
	return 0;
}
