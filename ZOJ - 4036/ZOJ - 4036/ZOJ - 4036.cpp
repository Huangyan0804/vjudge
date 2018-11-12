#include<iostream>
#include<string>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, b, a[101];
		string ans = "No";
		cin >> n >> b;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if ((a[i] + b) % 7 == 0)
				ans = "Yes";
		}
		cout << ans << endl;
	}
	return 0;
}