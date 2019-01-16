/*#include<iostream>
#include<string.h>
using namespace std;
char character[] = { "AEHIJLMOSTUVWXYZ12358" };
char Reverse[] = { "A3HILJMO2TUVWXY51SEZ8" };
int mirror(char c[],int n) {
	int flag = 0;
	for (int i = 0; i < (n + 1) / 2; i++) {
		for (int j = 0; j < strlen(character)-1; j++) {
			if (c[i] == character[j]) {
				flag = 1;
				if (c[n - 1 - i] != Reverse[j])
					return 0;
			}
		}
		if (flag)
			flag = 0;
		else
			return 0;
	}
	return 1;
}
int palindrome(char c[],int n) {
	for (int i = 0; i < (n + 1) / 2; i++) {
		if (c[i] != c[n - 1 - i]) {
			return 0;
		}
	}
	return 1;
}
int main() {
	char c[100];
	while (cin>>c){
		int m = 0, p = 0;
		if (mirror(c, strlen(c)))
			m = 1;
		if (palindrome(c, strlen(c)))
			p = 1;
		if (p == 0 && m == 0)
			cout << c << " -- is not a palindrome." << endl << endl;
		else if (p == 1 && m == 0)
			cout << c << " -- is a regular palindrome." << endl << endl;
		else if (p == 0 && m == 1)
			cout << c << " -- is a mirrored string." << endl << endl;
		else if (p == 1 && m == 1)
			cout << c << " -- is a mirrored palindrome." << endl << endl;
	}
	return 0;
}*/
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int main() {
	string s, a, b;
	char m[300];
	memset(m, NULL, sizeof(m));
	m['A'] = 'A';
	m['E'] = '3';
	m['H'] = 'H';
	m['I'] = 'I';
	m['J'] = 'L';
	m['L'] = 'J';
	m['M'] = 'M';
	m['O'] = 'O';
	m['S'] = '2';
	m['T'] = 'T';
	m['U'] = 'U';
	m['V'] = 'V';
	m['W'] = 'W';
	m['X'] = 'X';
	m['Y'] = 'Y';
	m['Z'] = '5';
	m['1'] = '1';
	m['2'] = 'S';
	m['3'] = 'E';
	m['5'] = 'Z';
	m['8'] = '8';
	while (cin >> s) {
		a = b = "";
		int len = s.size();
		for (int i = len - 1; i >= 0; i--) {
			a += s[i];
			b += m[s[i]];
		}
		if (s == a && s == b)
			cout << s << " -- is a mirrored palindrome." << endl << endl;
		else if (s == a && s != b)
			cout << s << " -- is a regular palindrome." << endl << endl;
		else if (s != a && s == b)
			cout << s << " -- is a mirrored string." << endl << endl;
		else
			cout << s << " -- is not a palindrome." << endl << endl;
	}
	return 0;
}