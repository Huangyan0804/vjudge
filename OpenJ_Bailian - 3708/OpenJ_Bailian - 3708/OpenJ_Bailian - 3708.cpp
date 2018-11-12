#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	while (n--){
		int num, r, ans = 0;
		cin >> num;
		while (num > 0) {
			r = num % 2;
			num /= 2;
			if (r == 1)
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}