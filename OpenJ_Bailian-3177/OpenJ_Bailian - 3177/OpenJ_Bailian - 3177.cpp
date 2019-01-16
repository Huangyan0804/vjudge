#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int ss(int a)
{
	if (a == 1) return 0;
	for (int i = 2; i <= sqrt(a); i++) {
		if (a%i == 0)
			return 0;
	}
	return 1;
}
int main() {
	int m, n, ans = 0;
	cin >> m >> n;
	if (m > n)
		swap(m, n);
	for (int i = m; i <= n; i++) {
		if (ss(i))
			ans++;
	}
	cout << ans;
	return 0;
}