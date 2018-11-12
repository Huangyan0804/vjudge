#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main() {
	const int N = 101;
	int n, m;
	int f[N] = { 0 };
	int w, v, s;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		cin >> v >> w >> s;
		for (int j = m; j >= 0; j--) {
			for (int k = 1; k <= s && k * v <= j; k++) {
				f[j] = max(f[j], f[j - k * v] + w * k);
			}
		}
	}
	cout << f[m] << endl;
	return 0;
}