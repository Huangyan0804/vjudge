#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main() {
	int t;
	int n, m;
	int a, b;
	cin >> t;
	while (t > 0) {
		int arr[105];
		cin >> n >> m;
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
		}
		for (int j = 0; j < m; j++) {
			cin >> a >> b;
			if (a > 0)
				arr[b-1] *= 2;
			else if (a < 0)
				arr[b-1] += 2;
		}
		sort(arr, arr + n);
		cout << arr[n-1] << endl;
		t--;
	}
	return 0;
}