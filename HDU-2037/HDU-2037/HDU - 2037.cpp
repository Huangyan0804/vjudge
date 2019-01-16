#include<iostream>
#include<algorithm>
using namespace std;
struct Time {
	int start, end;
}t[101];
bool cmp(const Time a,const Time b) {
	return a.end < b.end;
}
int main() {
	int n;
	while (cin >> n && n) {
		for (int i = 0; i < n; i++)
			cin >> t[i].start >> t[i].end;
		sort(t, t + n, cmp);
		int end = t[0].end;
		int ans = 1;
		for (int i = 1; i < n; i++) {
			if (t[i].start >= end) {
				ans++;
				end = t[i].end;
			}
		}
		cout << ans << endl;
	}
	return 0;
}