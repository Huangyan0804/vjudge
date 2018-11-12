#include<iostream>
#include<string>
using namespace std;
int sum(int n) {
	int r, sum = 0;
	while (n > 0) {
		r = n % 10;
		sum += r;
		n /= 10;
	}
	return sum;
}
int main() {
	int  n;
	cin >> n;
	while (n--) {
		int a;
		bool flag = false;
		cin >> a;
		for (int i = a - 45; i < a; i++) {
			if (sum(i) + i == a) {
				cout << i << endl;
				flag = true;
				break;
			}
		}
		if (!flag)
			cout << "0" << endl;
	}
	return 0;
}