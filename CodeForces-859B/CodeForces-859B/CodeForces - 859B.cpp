#include<iostream>
#include<math.h>
using namespace std;
int main() {
	int n;
	int ans;
	int number[1003];
	number[0] = 0;
	for (int i = 1; i <= 1001; i++)
		number[i] = i * i;
	cin >> n;
	int flag;
	for (int i = (int)sqrt((double)n)-1; i <= 1001; i++) {
		if (n < number[i]) {
			flag = i - 1;
			break;
		}
	}
	int left = n - flag * flag;
	if (left == 0)
		ans = flag * 4;
	else if (left > 0 && left <= flag) {
		ans = flag * 2 + 2 * (flag + 1);
	}
	else if (left > flag && left <= 2 * flag) {
		ans = (flag + 1) * 4;
	}
	cout << ans << endl;
	return 0;
}