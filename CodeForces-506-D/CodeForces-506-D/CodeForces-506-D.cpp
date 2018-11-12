#include<iostream>
#include<algorithm>
#include<string>
#include<set>
#include<vector>
#include<sstream>
using namespace std;
int main() {
	int n, k;
	int a[20001];
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<string> st;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			st.push_back(to_string(a[i]) + to_string(a[j]));
			st.push_back(to_string(a[j]) + to_string(a[i]));
		}
	}
	int ans = 0;
	for (auto i = st.begin(); i != st.end(); i++) {
		if (stoll(*i) % k == 0)
			ans++;
	}
	cout << ans << endl;
	return 0;
}