#include<iostream>
#include<string>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--){
		string a;
		int num[100] = { 0 };
		double ans;
		cin >> a;
		for (auto iter = a.begin(); iter != a.end(); iter++) {
			if (*iter == 'C'|| *iter == 'H'|| *iter == 'O'|| *iter == 'N') {
				auto tempiter = iter;
				int tempnum = 0;
				if (++tempiter != a.end() && *tempiter < 64) {
					while (tempiter != a.end() && *tempiter < 64) {
						tempnum = tempnum * 10 + *tempiter - 48;
						tempiter++;
					}
				}
				else {
					num[*iter]++;
				}
				num[*iter] += tempnum;
			}
		}
		ans = num['C'] * 12.01 + num['H'] * 1.008 + num['O'] * 16.00 + num['N'] * 14.01;
		printf("%.3f\n", ans);
	}
	return 0;
}