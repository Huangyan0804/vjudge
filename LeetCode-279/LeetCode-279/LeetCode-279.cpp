#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int numsquares(int n) {
	vector<int> f(n + 1, n);
	queue<int> q;
	f[0] = 0;
	q.push(0);
	while (!q.empty()) {
		int s = q.front();
		if (s == n)
			break;
		q.pop();
		for (int i = 1; s + i * i <= n; i++) {
			if (f[s + i * i] > f[s] + 1) {
				f[s + i * i] = f[s] + 1;
				q.push(s + i * i);
			}
		}

	}
	return f[n];
}
int main() {
	int n;
	cin >> n;
	cout << numsquares(n) << endl;

	return 0;
}