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
	int n, a[100001];
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int ans[100001];
		int k = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				ans[k++] = abs(a[j] - a[i]);
			}
		}
		sort(ans, ans + k);
		int minnum = ans[0];
		int number = 0;
		for (int i = 0; i < k; i++) {
			if (minnum == ans[i])
				number++;
			else
				break;
		}
		cout << minnum << ' ' << number << endl;
	}
	return 0;
}