#include<iostream>
using namespace std;
int main() {
	int a1, a2, a3;
	int temp, max;
	cin >> a3;
	if ((a1 + a2) % 2 == 0 && (a2 + a3) % 3 == 0 && (a1 + a2 + a3) % 5 == 0) {
		temp = a1 + a2 + a3;
		if (temp > max)
			max = temp;
	}
	return 0;
}