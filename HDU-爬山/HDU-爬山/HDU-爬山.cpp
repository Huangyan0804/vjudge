#include<iostream>
#include<algorithm>
#include<climits>
#include<cmath>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int a[100001];
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int ans = 0;
		int minnum = INT_MAX;
		int tempnum;
		sort(a, a + n);
		for (int i = 0; i < n - 1 ; i++) {
			tempnum = abs(a[i] - a[i + 1]);
			minnum = min(minnum, tempnum);
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				tempnum = abs(a[j] - a[i]);
				if (tempnum == minnum)
					ans++;
			}
		}
		cout << minnum << ' ' << ans << endl;
	}
	return 0;
}