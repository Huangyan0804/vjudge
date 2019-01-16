#include<iostream>
#include<string>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int score = 0;
		int ans = 0;
		for (auto iter = s.begin(); iter != s.end(); iter++) {
			if (*iter == 'O') {
				score++;
				ans += score;
			}
			else {
				score = 0;
			}
		}
		cout << ans << endl;
	}
	return 0;
}