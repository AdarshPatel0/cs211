#include <iostream>
using namespace std;

typedef double (*func)(double);
const double square_size =.0001;

double integrate(func f,double a, double b){
	double sum = 0;
	for(double i = a; i<b;i+=square_size){
		sum+=f(i)*square_size;
	}
	return sum;
}

double line(double x){
   return x;
}

double square(double x){
   return x*x;
}

double cube(double x){
   return x*x*x;
}

int main(){
	cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5) << endl;     // 12
	cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl; // 41.3333
	cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;   // 156
	return 0;
}