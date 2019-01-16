#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int a, jsnum = 0, osnum = 0, js[10], os[10];
	for (int i = 0; i < 10; i++) {
		cin >> a;
		if (a % 2 == 0)
			os[osnum++] = a;
		else
			js[jsnum++] = a;
	}
	sort(js, js + jsnum);
	sort(os, os + osnum);
	for (int i = 0; i < jsnum ; i++)
		cout << js[i] << " ";
	for (int i = 0; i < osnum; i++)
		cout << os[i] << " ";
	return 0;
}