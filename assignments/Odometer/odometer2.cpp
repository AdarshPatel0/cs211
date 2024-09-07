#include <iostream>

using namespace std;

int main(){
    int win[6] = {};
    for(int w=5; w>=0; w--){
        for (int i = 0; i < 10; i++) {
            win[w] = i;
			for (int i = 0; i < 6; i++) {
				cout << win[i];
			}
			cout << endl;
        }
    }
    return 0;
}
