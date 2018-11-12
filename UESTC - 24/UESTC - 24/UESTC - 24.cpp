#include<iostream>
using namespace std;
int main() {
	int n;
	while (cin >> n && n) {
		char ball[20];
		int r = 0, y = 0;
		cin >> ball;
		for (int i = 0; i < n; i++) {
			if (ball[i] == 'Y')
				y++;
			else if (ball[i] == 'R')
				r++;
			if (ball[i] == 'B'&&r == 7)
				cout << "Red" << endl;
			else if (ball[i] == 'B'&&r != 7)
				cout << "Yellow" << endl;
			if (ball[i] == 'L'&&y == 7)
				cout << "Yellow" << endl;
			else if (ball[i] == 'L'&&r != 7)
				cout << "Red" << endl;
		}
	}
	return 0;
}