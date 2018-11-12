#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main() {
	int m;
	cin >> m;
	while (m--) {
		int a[501];
		int n;
		int ans = 0;
		cin >> n
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		int mid = n / 2;
		for (int i = 0; i < n; i++) {
			ans += abs(a[mid] - a[i]);
		}
		cout << ans << endl;
	}
	return 0;
}