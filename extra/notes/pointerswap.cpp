#include <iostream>

using namespace std;

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b= t;
}

int main(){
    int a = 10;
    int b = 20;
    swap(&a,&b);
    cout << a << " " << b << endl;
}