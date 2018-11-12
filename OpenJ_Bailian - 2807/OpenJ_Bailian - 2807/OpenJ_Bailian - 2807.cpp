#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int a[17];
	int i = -1;
	int ans = 0;
	while (cin >> a[++i] && a[i]);
		sort(a, a + i);
		for (int j = 1; j < i ; j++) {
			for (int i = 0; i < j; i++) {
				if (a[i] * 2 == a[j])
					ans++;
			}
		}
	cout << ans << endl;
	return 0;
}