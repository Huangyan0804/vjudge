#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[100001];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int m, searc;
	cin >> m;
	for (int k = 0; k < m; k++) {
		cin >> searc;
		int i = 0, j = n - 1, mid;
		if (a[0] > searc) {
			cout << a[0] << endl;
			continue;
		}
		if (a[n - 1] < searc) {
			cout << a[n - 1] << endl;
			continue;
		}
		while (i < j) {
			mid = (i + j) / 2;
			if (searc < a[mid])
				j = mid;
			else
				i = mid + 1;
		}
		if (a[i] == searc) {
			cout << a[i] << endl;
			continue;
		}
		if (abs(a[i] - searc) < abs(a[i-1] - searc)) {
			cout << a[i] << endl;
			continue;
		}
		else {
			cout << a[i - 1] << endl;
			continue;
		}
	}
	return 0;
}