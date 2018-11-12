#include<iostream>
#include<stdlib.h>
using namespace std;
int main() {
	int numbers, friends, max = 0;
	char colors[300];
	int a[27] = { 0 };
	int ch;
	int i = 0;
	cin >> numbers >> friends;
	cin >> colors;
	for (int i = 0; i < numbers; i++) {
		ch = colors[i];
		a[ch - 97]++;
		if (a[ch - 97] > max)
			max = a[ch - 97];
	}
	if (max > friends)
		cout << "NO";
	else
		cout << "YES";
	//system("pause");
	return 0;
}