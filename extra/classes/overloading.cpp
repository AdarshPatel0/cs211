#include <iostream>

using namespace std;

class bucket{
	public:
	int amount;
	bucket(int a = 0){
		amount = a;
	}
	bucket operator+(bucket &obj){
		bucket res(amount + obj.amount);
		return res;
	}
	bucket operator-(bucket &obj){
		bucket res(amount - obj.amount);
		return res;
	}
};


ostream& operator <<(ostream &os,const bucket &obj){
	os << obj.amount;
	return os;
};

int main(){
	bucket obj1(5);
	bucket obj2(4);
	bucket obj3 = obj1 + obj2;
	cout << (obj1+obj2) << endl;
	return 0;
}