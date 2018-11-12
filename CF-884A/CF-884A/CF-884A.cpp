#include<iostream>
#include<stdlib.h>
using namespace std;
int main() {
	const int Daytime = 86400;
	int days, time;
	int worktime[101];
	int ans=0;
	cin >> days >> time;
	for (int i = 0; i < days; i++) {
		cin >> worktime[i];
			time -= Daytime - worktime[i];
			ans++;
		if (time <= 0)
			break;
	}
	cout << ans;
	//system("pause");
	return 0;
}