#include<iostream>
#include<string>
#include<cctype>
#include<stack>
using namespace std;
struct matrix {
	int x;
	int y;
	matrix (int x=0, int y=0):x(x),y(y) {}
}m[27];
int main() {
	int n;
	char c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		cin >> m[c - 'A'].x >> m[c - 'A'].y;
	}
	string s;
	while (cin >> s) {
		int ans = 0;
		int ok = 1;
		stack<matrix> sta;
		for (int i = 0; i < s.length(); i++) {
			if (isalpha(s[i]))
				sta.push(m[s[i]-'A']);
			else if (s[i] == ')') {
				matrix mat1 = sta.top();
				sta.pop();
				matrix mat2 = sta.top();
				sta.pop();
				if (mat1.x == mat2.y) {
					ans += mat1.y * mat2.x * mat2.y;
					sta.push(matrix(mat2.x, mat1.y));
				}
				else {
					ok = 0;
					break;
				}
			}
		}
		if (ok)
			cout << ans << endl;
		else
			cout << "error" << endl;
	}
	return 0;
}