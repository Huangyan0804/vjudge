#include<iostream>
using namespace std;
int main() {
	int a[5][5], max, min;
	int maxj = 0, maxi = 0;
	int find = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		max = a[i][0];
		for (int j = 0; j < 5; j++) {
			if (a[i][j] >= max) {
				max = a[i][j];
				maxj = j;
				maxi = i;
			}
		}
		min = a[0][maxj];
		for (int t = 0; t < 5; t++) {
			if (a[t][maxj] <= min) {
				min = a[t][maxj];
			}
		}
		if (max == min) {
			cout << maxi+1 << " " << maxj+1 << ' ' << max << endl;
			find = 1;
		}
	}
	if (find == 0)
		cout << "not found" << endl;
	return 0;
}