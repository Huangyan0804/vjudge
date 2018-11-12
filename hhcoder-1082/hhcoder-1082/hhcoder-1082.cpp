#include<iostream>
#include<string>
#include<algorithm>
#include <cctype>
using namespace std;
int main() {
	string s, temp;
	while (getline(cin, s)) {
		temp = s;
		int pos = 0;
		transform(s.begin(), s.end(), temp.begin(), ::tolower);
		while (temp.find("marshtomp", pos) != temp.npos) {
			pos = temp.find("marshtomp");
			temp.replace(pos, 9, "fjxmlhx");
			s.replace(pos, 9, "fjxmlhx");
		}
		cout << s << endl;
	}
	return 0;
}