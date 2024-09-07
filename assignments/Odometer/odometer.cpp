#include <iostream>

using namespace std;

int main() {
	int win[6] = {};
	for (int i = 0; i < 10; i++) {
		win[0] = i;
		for (int i = 0; i < 10; i++) {
			win[1] = i;
			for (int i = 0; i < 10; i++) {
				win[2] = i;
				for (int i = 0; i < 10; i++) {
					win[3] = i;
					for (int i = 0; i < 10; i++) {
						win[4] = i;
						for (int i = 0; i < 10; i++) {
							win[5] = i;
							for (int i = 0; i < 6; i++) {
								cout << win[i];
							}
							cout << endl;
						}
					}
				}
			}
		}
	}
	return 0;
}