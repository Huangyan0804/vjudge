#include<iostream>
#include<string>
using namespace std;
int leepYear(long year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	else
		return 0;
}
int main() {
	string m[12] = { "January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November" , "December" };
	int n; string s1, s2;
	cin >> n;
	getchar();
	for (int t = 1; t <= n; t++) {
		int ans = 0;
		int year[3], month[3], day[3];
		getline(cin, s1);
		getline(cin, s2);
		year[1] = stoi(s1.substr(s1.find(',') + 1));
		year[2] = stoi(s2.substr(s2.find(',') + 1));
		day[1] = stoi(s1.substr(s1.find(" "), s1.find(",")));
		day[2] = stoi(s2.substr(s2.find(" "), s2.find(",")));
		for (int i = 0; i < 12; i++) {
			if (s1.find(m[i]) != s1.npos)
				month[1] = i + 1;
			if (s2.find(m[i]) != s2.npos)
				month[2] = i + 1;
		}
		ans = (year[2] / 4 - year[1] / 4) - (year[2] / 100 - year[1] / 100) + (year[2] / 400 - year[1] / 400);
		if (leepYear(year[1])) {
			if (month[1] < 2 || month[1] == 2 && day[1] <= 29)
				ans++;
		}
		if (leepYear(year[2])) {
			if (month[2] < 2 || month[2] == 2 && day[2] < 29)
				ans--;
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}