#include<iostream>
#include<string>
#include <strstream>
using namespace std;

int stringToInt(const string &s)
{
	int val;
	strstream ss;
	ss << s;
	ss >> val;
	return val;
}
struct kid{
	char name[15];
	int kill;
}kids[65];
int main() {
	int n, w, s, p = 1;
	cin >> n;
	int num = n;
	string str;
	for (int i = 1; i <= n; i++) {
		cin >> kids[i].name;
		kids[i].kill = 0;
	}
	cin >> str;
	int pos = str.find(',');
	w = stringToInt(str.substr(0, pos));
	s = stringToInt(str.substr(pos + 1));
	int i = w;
	for (i; i <= n + 1; i++) {
		if (i == n + 1)
			i = 1;
		if (kids[i].kill == 0) {
			if (p == s) {
				p = 1;
				kids[i].kill = 1;
				cout << kids[i].name << endl;
				num--;
			}
			else {
				p++;
			}
			if (num == 0)
				break;
		}
	}
	return 0;
}