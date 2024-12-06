#include <iostream>

using namespace std;

class bucket{
	private:
	void checkMaterial(bucket obj){
		if(material != obj.material){
			cout << "Error!!! These buckets have different liquids!" << endl;
			exit(-1);
		}
	}
	public:
	int amount;
	string material;
	bucket(){
		amount = 0;
		material = "Water";
	}
	bucket(int a = 0,string b = "Water"){
		amount = a;
		material = b;
	}
	bucket operator+(bucket &obj){
		checkMaterial(obj);
		bucket res(amount + obj.amount,material);
		return res;
	}
	bucket operator-(bucket &obj){
		checkMaterial(obj);
		bucket res(abs(amount - obj.amount));
		return res;
	}
	bool operator==(bucket &obj) {
    return (obj.material == material && obj.amount == amount);
	}
	bool operator!=(bucket &obj){
		if(obj.material != material || obj.amount != amount){
			return true;
		}
		return false;
	}
	void operator<<(bucket &obj){
		checkMaterial(obj);
		amount+=obj.amount;
		obj.amount = 0;
		return;
	}
	void operator>>(bucket &obj){
		checkMaterial(obj);
		obj.amount+=amount;
		amount = 0;
		return;
	}
	int getAmount() const {return amount;}
	string getMaterial() const {return material;}
	void setAmount(int &n){amount = n;}
	void setMaterial(string a){material = a;}
};

ostream &operator <<(ostream &os,const bucket &obj){
	os << obj.getAmount() << " oz of " << obj.getMaterial();
	return os;
};

int main(){
	bucket bucketA(5);
	bucket bucketB(4);
	bucketA << bucketB;
	bucketA >> bucketB;
	bucketB.setMaterial("Honey");
	cout << bucketA << endl << bucketB << endl;
	cout << (bucketA == bucketB) << endl;
	cout << (bucketA != bucketB) << endl;
	return 0;
}