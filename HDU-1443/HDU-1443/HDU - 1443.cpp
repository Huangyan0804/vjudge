#include<iostream>
using namespace std;
int main() {
	int ans[15];
	
	for (int k = 1; k < 14; k++) {
		for (int j = k;; j++) {
			int start = 0;
			int flag = 0;
			int live = 2 * k;
			int temp, i = k * 2;
			while (live > k) {
				temp = (start + j - 1) % live;
				if (temp < k)
					break;
				start = temp;
				live--;
				if (live == k) {
					ans[k] = j;
					flag = 1;
					break;
				}
			}
			if (flag) {
				flag = 0;
				break;
			}
		}
	}
	int n;
	while (cin >> n&&n) {
		cout << ans[n ] << endl;
	}
	return 0;
}