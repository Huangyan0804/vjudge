#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	long m;
	int n;
	while (cin >> m >> n && n) {
		long iq[1001];
		int ans = 0;
		for (int i = 0; i < n; i++)
			cin >> iq[i];
		for (int i = 0; i < n; i++) {
			if (m > iq[i]) {
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}