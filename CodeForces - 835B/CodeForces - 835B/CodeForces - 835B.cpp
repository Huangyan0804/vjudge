#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	string n;
	int k;
	cin >> k;
	cin >> n;
	int ans = 0;
	int sum = 0;
	for (auto iter = n.begin(); iter != n.end(); iter++) {
		sum += *iter - '0';
	}
	if (sum < k) {
		sort(n.begin(), n.end());
		for (auto iter = n.begin(); iter != n.end(); iter++) {
			sum += 9-(*iter - '0');
			ans++;
			if (sum >= k)
				break;
		}
	}
	cout << ans << endl;
	return 0;
}