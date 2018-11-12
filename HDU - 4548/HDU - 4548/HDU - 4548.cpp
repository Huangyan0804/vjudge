#include<iostream>
using namespace std;
int num[1000001] = { 0 };
int ans[1000001];
void prime(int n) {
	int cnt = 0;
	num[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (num[i] == 0) {
			for (int j = i * 2; j <= n; j += i) {
				num[j] = 1;
			}
		}
	}
}

int cut(int n) {
	int ans = 0;
	while (n > 0) {
		ans += n % 10;
		n /= 10;
	}
	return ans;
}

void caculate() {
	int cnt = 0;
	for (int i = 2; i <= 1000001; i++) {
		if (num[i] == 0){
			if (num[cut(i)] == 0) {
				cnt++;
			}
		}
		ans[i] = cnt;
	}
}

int main() {
	prime(1000001);
	caculate();
	int t;
	cin >> t;
	for (int k = 1; k <= t; k++) {
		int l, r;
		int res;
		cin >> l >> r;
		res = ans[r] - ans[l-1];
		printf("Case #%d: %d\n", k, res);
	}
	return 0;
}