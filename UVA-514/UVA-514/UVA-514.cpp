#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
int main() {
	int n;
	while (cin >> n && n) {
		int target[1005];
		
		while (cin >> target[1]) {
			stack<int> s;
			if (target[1] == 0)
				break;
			for (int i = 2; i <= n; i++)
				cin >> target[i];
			int A = 1, B = 1;
			bool ok = 1;
			while (B < n) {
				if (A == target[B]) {
					A++;
					B++;
				}
				else if (!(s.empty()) && target[B] == s.top()) {
					s.pop();
					B++;
				}
				else if (A <= n)
					s.push(A++);
				else {
					ok = false;
					break;
				}
			}
			if (ok)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		cout << endl;
	}
	return 0;
}