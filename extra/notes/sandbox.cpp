#include <iostream>

using namespace std;

int main(){
	setlocale(LC_ALL, "en_US.UTF-8");
	wcout << int(L'┐') << endl;
	wcout << int(L'┌') << endl;
	wcout << int(L'└') << endl;
	wcout << int(L'┘') << endl;
	wcout << int(L'│') << endl;
	wcout << int(L'─') << endl;
	wcout << wchar_t(9608) << endl;
	return 0;
}