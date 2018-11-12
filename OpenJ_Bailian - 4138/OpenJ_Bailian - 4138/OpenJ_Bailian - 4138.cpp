#include<iostream>
using namespace std;
int prime[100001];
int k;
void isprime(int a) {
	int num[10001] = { 0 };
	k = 0;
	for (int i = 2; i <= a; i++) {
		if (num[i] != 1) {
			prime[k++] = i;
			for (int j = i+i; j <= a; j+=i) {
				num[j] = 1;
			}
		}
	}
}
int main() {
	int s, i, j;
	long max = 0, temp;
	cin >> s;
	isprime(s);
	for (i=0; i < k; i++) {
		for (j=k-1; j >= i; j--) {
			if (i > j)
				break;
			if (prime[i] + prime[j] == s) {
				temp = prime[i] * prime[j];
				if (temp > max)
					max = temp;
			}
		}
	}
	cout << max;
	return 0;
}