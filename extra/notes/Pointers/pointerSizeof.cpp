#include <iostream>

using namespace std;

int main(){
	int a[]{10,20,30}, b[3][4] = {};
	cout << a << " " << a+1 << endl; //Address of a[0] address of a [1]. The difference is 4 since there is a 4 byte difference between the start of a[0] and a[1].
	//Pointer arithmetic on a array works by taking the current pointer "a" and increasing it by n * the size of the data type
	cout << sizeof((a+1)) << endl; // (a+1) is converted into a pointer type
	cout << sizeof(b) << endl; //b is converted into a stack of 12 elements since 3*4 = 12. the byte size of integers * #elements is 12*4 = 48
	cout << sizeof(*(b+1)) << endl; //*(b+1) is the object b[1]. b[1] is the pointer to b[1][0]. the size of b[1][0] is 4 elements * byte size of integer (4) = 16 bytes
	cout << " b is: " << b << endl; //b is the address to b[0]. This happens to also be the adress to b[0][0]
	cout << " b+1 is: " << b+1 << endl; //b+1 is the address to b[1]. The difference of b and b+1 is 16 since the size of an element of b is 16 bytes which comes from 4 elements * 4bytes per element
	cout << " &b is: " << &b << endl; //&b is the address of the start of the stack b (b[0] or b[0][0])
	cout << " &b+1 is: " << &b+1 << endl; //&b+1 is the address of the start of the stack b * n*size of the stack. The difference between &b and &b+1 is (3*4)*4 size of = 48
	return 0;
}