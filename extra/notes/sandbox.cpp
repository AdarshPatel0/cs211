#include <iostream>

using namespace std;

int main(){
	std::setlocale(LC_ALL, "en_US.UTF-8");
	wchar_t myChar = L'\u2588';
	wcout << myChar << endl;
	return 0;
}