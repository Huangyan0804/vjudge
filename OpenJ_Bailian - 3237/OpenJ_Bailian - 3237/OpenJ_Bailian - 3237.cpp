#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	while (n--) {
		int leg, maxnum, minnum, temp;
		cin >> leg;
		if (leg % 2 == 0) {
			maxnum = leg / 2;
			if (leg % 4 == 0)
				minnum = leg / 4;
			else {
				temp = leg % 4;
				temp /= 2;
				minnum = leg / 4 + temp;
			}
		}
		else {
			cout << "0 0" << endl;
			continue;
		}
		cout << minnum << ' ' << maxnum << endl;
	}
	return 0;
}