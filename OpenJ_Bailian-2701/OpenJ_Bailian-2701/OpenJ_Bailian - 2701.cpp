#include<iostream>
#include<string.h>
using namespace std;
int main() {
	int num[101], n, ans = 0;
	memset(num, 1, sizeof(num));
	cin >> n;
	for (int i = 7; i <= n; i++) {
		if (i % 7 == 0 || i % 10 == 7 || i / 10 == 7)
			num[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		if (num[i]) {
			ans += i * i;
		}
	}
	cout << ans << endl;
	return 0;
}