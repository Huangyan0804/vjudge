#include<iostream>
using namespace std;
int main() {
	int h;
	cin >> h;
	double high = h, length = 0;
	
	length += h;
	for (int i = 0; i < 9; i++) {
		high /= 2;
		length += high * 2;
	}
	high /= 2;
	cout << length << endl << high << endl;
	return 0;
}