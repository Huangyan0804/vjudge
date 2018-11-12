#include<iostream>
#include<algorithm>
using namespace std;

struct ls
{
	int money;
	double temp;
	int greed;
}a[51];

int main() {
	int q;
	cin >> q;
	while (q--) {
		int n, ans = 0, maxn = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i].temp >> a[i].greed;
			a[i].money = a[i].temp * 10;
		}
		for (int i = 0; i < n; i++) {
			if (a[i].money % 50 == 0) {
				if (maxn < a[i].greed)
					maxn = a[i].greed;
			}
		}
		for (int i = 0; i < n-1; i++) {
			for (int j = i + 1; j < n; j++) {
				int temp = a[i].greed + a[j].greed;
				if ((a[i].money + a[j].money) % 50 == 0) {
					if (maxn < temp)
						maxn = temp;
				}
			}
		}
		for (int i = 0; i < n - 2; i++) {
			for (int j = i + 1; j < n-1; j++) {
				for (int k = j + 1; k < n; k++) {
					int temp = a[i].greed + a[j].greed + a[k].greed;
					if ((a[i].money + a[j].money + a[k].money) % 50 == 0) {
						if (maxn < temp)
							maxn = temp;
					}
				}
			}
		}
		cout << maxn << endl;
	}
	return 0;
}