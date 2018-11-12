#include<iostream>
#include<stdlib.h>
using namespace std;
int day(int a, int b, int c, int d) {
	int ans = 0;
	int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = a; i < c; i++) {
		ans += month[i];
	}
	ans = ans + d - b;
	return ans;
}
int main() {
	int n;
	cin >> n;
	while (n > 0) {
		int am, ad, anum, bm, bd;
		cin >> am >> ad >> anum >> bm >> bd;
		for (int i = 0; i < day(am, ad, bm, bd); i++) {
			anum *= 2;
		}
		cout << anum << endl;
		n--;
	}
	return 0;
}