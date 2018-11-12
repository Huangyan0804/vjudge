#include<iostream>
#include<stdlib.h>
using namespace std;
int main() {
	int a, b, n;
	int f[49];
	f[1] = 1;
	f[2] = 1;
	while (cin >> a >> b >> n && a+b+n) {
		int t = 1;
		for (int i = 3; i <= 49; i++) {
			f[i] = (a*f[i - 1] + b * f[i - 2]) % 7;
		}
		cout << f[n%49] << endl;
	}
	return 0;
}