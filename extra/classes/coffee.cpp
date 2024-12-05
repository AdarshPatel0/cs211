#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

class cup{
	public:
	int size;
};

class coffeeCup : public cup{
	public:
	string liquid = "Coffee";
	coffeeCup(){
		size = 1;
	}
	coffeeCup(int s){
		size = s;
	}
};

int main(){
	coffeeCup myCoffee(3);
	cout << myCoffee.size << " oz of " << myCoffee.liquid << endl;
	return 0;
}