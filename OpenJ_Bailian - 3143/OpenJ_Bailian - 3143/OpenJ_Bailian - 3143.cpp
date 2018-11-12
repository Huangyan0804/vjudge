#include<iostream>
using namespace std;
int prime[2000];
int num[2001] = { 0 };
int k;
void isprime(int n) {
	k = 0;
	for (int i = 2; i <= n; i++) {
		if (num[i] == 0) {
			prime[k++] = i;
			for (int j = i * 2; j <= n; j += i)
				num[j] = 1;
		}
	}
}
int main() {
	isprime(2000);
	int x;
	cin >> x;
	if (x < 6 || x % 2 != 0) {
		cout << "Error!" << endl;
		return 0;
	}
	for (int i = 0; i <= k; i++) {
		int j = i;
		if (prime[j] + prime[i] > x)
			break;
		for (;j <= k; j++) {
			if (prime[i] + prime[j] > x)
				break;
			if (prime[i] + prime[j] == x)
				cout << x << "=" << prime[i] << "+" << prime[j] << endl;
		}
	}
	system("pause");
	return 0;
}