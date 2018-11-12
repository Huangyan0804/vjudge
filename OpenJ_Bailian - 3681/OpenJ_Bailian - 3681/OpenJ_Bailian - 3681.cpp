#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int num[5], a;
	while (cin >> a) {
		int sum = 0;
		for (int i = 0; i < 5; i++)
			cin >> num[i];
		for (int i = 0; i < 5; i++) {
			if (num[i] < a)
				sum += num[i];
		}
		cout << sum << endl;
	}
	return 0;
}