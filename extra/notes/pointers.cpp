#include <iostream>

using namespace std;

int main(){
    int myNums[4] = {1,2,3,4};
    int* arr_begin = &myNums[0];
    int* arr_end = &myNums[4];
    for(int* current = arr_begin; current< arr_end ;current++){
        cout << arr_end - current << " " << *current;
    }
    return 0;
}