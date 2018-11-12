#include<iostream>
#include<stdlib.h>
using namespace std;
int length(int t, int v) {
	int ans;
	ans = t * v;
	return ans;
}
int main() {
	int t, k, u, v;
	int n;
	cin >> n;
	while (n > 0) {
		cin >> t >> k >> u >> v;
		if (length(t - k, u) > length(t, v)) {
			cout << '0' << endl;
		}
		else if (length(t - k, u) < length(t, v)) {
			cout << '1' << endl;
		}
		else
			cout << "-1" << endl;
		n--;
	}
	return 0;
}