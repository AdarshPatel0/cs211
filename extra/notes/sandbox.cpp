#include <iostream>

using namespace std;

class A{
	private:
	protected:
	int a;
	public:
	A(){a = 10;}
	friend class B;
};

class B:A{
	private:
	public:
	int getA(A& obj){return obj.a;}
};

int main(){
	A objA;
	B objB;
	cout << objB.getA(objA) << endl;
	return 0;
}