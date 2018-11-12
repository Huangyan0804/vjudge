#include<iostream>
#include<string>
using namespace std;
int main() {
	char F[] = { "ABCDEF" };
	int n;
	cin >> n;
	while (n--) {
		string s, ans = "";
		cin >> s;
		if (s.length() % 4 != 0) {
			int num = 4 - s.length() % 4;
			for (int i = 0; i < num; i++)
				s = '0' + s;
		}
		for (int i = 0; i < s.length(); i += 4) {
			int temp = 0;
			for (int j = i; j < i + 4; j++) {
				temp = temp * 2 + (s[j] - '0');
			}
			if (temp >= 10) {
				ans = ans + F[temp - 10];
			}
			else
				ans += (char)(temp + '0');
		}
		cout << ans << endl;
	}
	return 0;
}