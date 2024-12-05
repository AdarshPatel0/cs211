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
		bucket res(abs(amount - obj.amount));
		return res;
	}
};

ostream& operator <<(ostream &os,const bucket &obj){
	os << obj.amount;
	return os;
};

int main(){
	bucket bucketA(5);
	bucket bucketB(4);
	bucket bucketC = bucketA - bucketB;
	cout << "Bucket A has a volume of " << bucketA << ", and Bucket B has a volume of " << bucketB << endl;
	cout << "Both buckets combined have a volume of " << (bucketA+bucketB) << endl;
	cout << "The difference in volume between bucket A and bucket B is " << bucketC << endl;
	return 0;
}