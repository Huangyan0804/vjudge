#include<iostream>
#include<stdlib.h>

using namespace std;
int main() {
	int n;
	while (cin >> n && n) {
		int arr[210] = { 0 };
		int temp, max = 0;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			arr[temp + 101]++;
		}
		for (int i = 0; i < 210; i++) {
			if (arr[i] > arr[max])
				max = i;
		}
		cout << max - 101 << ' ' << arr[max] << endl;
	}
	return 0;
}