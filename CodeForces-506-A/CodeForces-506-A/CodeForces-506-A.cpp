#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	string t;
	cin >> t;
	int l = 0, r = n - 1;
	int maxn = 0;
	for (int k = n - 1; k > 0; k--) {
		int i = 0, j = k;
		while (i >= 0 && j < n && t[i] == t[j]) {
			i++;
			j++;
		}
		i--;
		j--;
		if (j == n - 1) {
			int len = i + 1;
			maxn = max(len, maxn);
		}
	}
	string tempstr = t.substr(maxn);
	string ans = t;
	for (int i = 0; i < k - 1; i++) {
		ans += tempstr;
	}
	cout << ans << endl;
	return 0;
}