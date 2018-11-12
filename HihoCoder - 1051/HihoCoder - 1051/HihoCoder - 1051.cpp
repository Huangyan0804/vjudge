#include<iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		int maxn = 0;
		int a[101];
		a[0] = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		if (m >= n ) {
			cout << "100" << endl;
		}
		else {
			for (int i = 1; i <= n - m; i++) {
				int temp;
				temp = a[i + m] - a[i - 1] - 1;
				if (maxn < temp)
					maxn = temp;
			}
			cout << maxn << endl;
		}
	}
	return 0;
}