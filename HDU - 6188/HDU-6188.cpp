#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define scanff(n) scanf("%d", &n)
int a[1000005];
int main() {
	int n;
	while (cin >> n) {
		memset(a, 0, sizeof a);
		int num;
		for (int i = 0; i < n; i++) {
			scanff(num);
			a[num]++;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] >= 2) {
				ans += a[i] / 2;
				a[i] %= 2;
			}
			if (a[i] && a[i + 1] & 1 && a[i + 2]) {
				ans++;
				a[i]--;
				a[i + 1]--;
				a[i + 2]--;
			}
		}
		cout << ans << endl;
	}
	return 0;
}