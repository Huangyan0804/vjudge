#include<iostream>
using namespace std;
int main() {
	int money, k;
	int year;
	while (cin >> money >> k) {
		int allmoney = 0;
		double houseMoney = 200;
		for (year = 1; year <= 20; year++) {
			allmoney += money;
			if (allmoney >= houseMoney) {
				cout << year << endl;
				break;
			}
			houseMoney *= 1 + (k * 0.01);
		}
		if (year > 20 && allmoney <= houseMoney)
			cout << "Impossible" << endl;
	}
	return 0;
}