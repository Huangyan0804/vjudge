#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	//5��ͷ�ģ�5��β�ģ�5û�н�β�ģ�5�м�ܶ�ġ�
	string s;
	while (cin >> s) {
		int a[1000] = { 0 };
		int i = 0;
		string::iterator iter = s.begin();
		while (*iter == '5')
			iter++;
		while (iter != s.end()) {
			if (*iter == '5') {
				while (iter != s.end()&&*iter == '5')
					iter++;
				iter--;
				i++;
			}
			else {
				a[i] *= 10;
				a[i] += *iter - 48;
			}
			if (iter != s.end())
				iter++;
		}
		iter--;
		if (*iter == '5')
			i--;
		sort(a, a + i+1);
		for (int j = 0; j <= i; j++) {
			if (j != i)
				cout << a[j] << ' ';
			else
				cout << a[j] << endl;
		}
	}
	return 0;
}