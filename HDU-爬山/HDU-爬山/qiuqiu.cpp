#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<sstream>
#include<vector>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--){
		int f[100001];
		int a[100001];
		int m, n;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i <= n; i++) {
			int j;
			for (j = m; j >= a[i]; j--) {
				f[j] = max(f[j], f[j - a[i]] + 1);
				if (f[j] == m)
					break;
			}
			if (f[j] == m)
				break;
		}
		cout << f[m] << endl;
	}
	return 0;
}