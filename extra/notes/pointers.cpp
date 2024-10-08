#include <iostream>

using namespace std;

int main(){
    int myNum = 2024;
    int* pointer = &myNum;
    cout << "This is my number by reference : " << myNum << endl;
    cout << "This is the memory address of my number : " << pointer << endl;
    cout << "This is my number by pointer : " << *pointer << endl;
    *pointer+=1;
    cout << "This is 1 plus my number : " << myNum << endl;
    return 0;
}