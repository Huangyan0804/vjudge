#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
string name[5] = { "Danil","Olya", "Slava","Ann","Nikita" };
int main() {
	string s;
	while (getline(cin, s)) {
		int ans = 0;
		for (int i = 0; i < 5; i++) {
			if (s.find(name[i]) != s.npos) {
				ans++;
				if (s.rfind(name[i]) != s.find(name[i])) 
					ans++;
			}
		}
			if (ans == 1)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
	}
	return 0;
}
//ע�����һ��������2���ظ�