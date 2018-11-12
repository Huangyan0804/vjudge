#include<iostream>
using namespace std;
int prime[30000];
int num[33000];
int ans;
int  gcd(int n,int m) {
	if (m == 0)
		return n;
	else
		return gcd(m, n%m);
}
int main() {
	int n;
	int num[33000] = { 0 };
	cin >> n;
	while (n--) {
		int m;
		int ans = 0;
		cin >> m;
		for (int i = 1; i < m; i++) {
			if (gcd(m,i) <= 1)
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}