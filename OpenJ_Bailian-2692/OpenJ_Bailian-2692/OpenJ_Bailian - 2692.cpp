#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int coin[12] = { 0 };
char Left[3][7], Right[3][7], Status[3][7];
bool judge() {
	for (int i = 0; i < 3; i++) {
		int lw = 0, rw = 0;
		for (int j = 0; j < strlen(Left[i]); j++) {
			lw += coin[Left[i][j] - 'A'];
		}
		for (int j = 0; j < strlen(Right[i]); j++) {
			rw += coin[Right[i][j] - 'A'];
		}
		if (lw == rw && Status[i][0] != 'e') {
			return false;
		}
		if (lw < rw && Status[i][0] != 'd') {
			return false;
		}
		if (lw > rw && Status[i][0] != 'u') {
			return false;
		}
	}
	return true;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		string anscoin, ansstaus;
		anscoin = "", ansstaus = "";
		coin[12] = { 0 };
		for (int i = 0; i < 3; i++)
			cin >> Left[i] >> Right[i] >> Status[i];
		for (int i = 0; i < 12; i++) {
			coin[i] = 1;
			if (judge()) {
				anscoin = (i + 'A');
				ansstaus = "heavy";
				break;
			}
			coin[i] = -1;
			if (judge()) {
				anscoin = (i + 'A');
				ansstaus = "light";
				break;
			}
			coin[i] = 0;
		}
		cout << anscoin << " is the counterfeit coin and it is " << ansstaus << "." << endl;
	}
	return 0;
}