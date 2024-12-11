#include <iostream>

using namespace std;

class A{
	protected:
	int x;
	int y;
	A(){
		x=2;
		y=3;
	}
};

class C:private A{
	friend class B;
	public:
	int * xPtr;
	C(){
		xPtr = &x;
	}
};

class B:public A{
	public:
	int getX(C &obj){
		return obj.x;
	}
	int * x;
	B(C&obj){
		x=&obj.x;
	}
	B(){}
};

int main(){
	C data;
	B obj(data);
	cout << *(obj.x) << endl;
	cout << *data.xPtr << endl;
	return 0;
}