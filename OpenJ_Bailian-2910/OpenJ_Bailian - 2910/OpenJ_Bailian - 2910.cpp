#include<iostream>
#include<ctype.h>
#include<string.h>
using namespace std;
int main() {
	char c[101];
	int a[31] = { 0 };
	int i = 0;
	int j = 0;
	cin >> c;
	while (!isdigit(c[j]))
		j++;
	for (j; j < strlen(c); j++) {
		if (isdigit(c[j])) {
			a[i] *= 10;
			a[i] += c[j]-48;
		}
		else {
			while (!isdigit(c[j]))
				j++;
			i++;
			j--;
		}
	}
	if (isdigit(c[strlen(c) - 1]))
		i++;
	for (int k = 0; k < i; k++)
		cout << a[k] << endl;
	return 0;
}