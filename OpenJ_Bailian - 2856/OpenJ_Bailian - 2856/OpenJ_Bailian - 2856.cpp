#include<iostream>
using namespace std;
int main() {
	double weight, ans;
	char exp;
	while (cin >> weight >> exp) {

		if (weight <= 1)
			ans = 0.8;
		else {
			ans = 0.8;
			weight -= 1;
			ans += weight * 0.5;
		}
		if (exp == 'y') {
			ans += 2;
		}
		cout << ans << endl;
	}
	return 0;
}