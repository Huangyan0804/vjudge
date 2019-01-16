#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int a[1000001];
bool cmp(int a, int b)
{
	return a > b;
}
int main() {
	int n, m;
	while (cin >> n >> m && n) {
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n, cmp);
		for (int i = 0; i < m; i++) {
			if(i!=m-1)
				printf("%d ", a[i]);
			else
				printf("%d\n", a[i]);
		}
	}
	return 0;
}