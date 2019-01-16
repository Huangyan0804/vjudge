#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>
#include<map>
#include<vector>
using namespace std;
map<string, int> dict;
string bzh(string s) {
	string ans = s;
	for (int i = 0; i < ans.length(); i++) {
		ans[i] = tolower(ans[i]);
	}
	sort(ans.begin(), ans.end());
	return ans;
}
int main() {
	string s;
	vector<string> word;
	while (cin >> s) {
		if (s[0] == '#')
			break;
		word.push_back(s);
		string r = bzh(s);
		if (!dict.count(r))
			dict[r] = 0;
		dict[r]++;
	}
	vector<string> ans;
	for(int i=0;i<word.size();i++){
		if (dict[bzh(word[i])] == 1) {
			ans.push_back(word[i]);
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	return 0;
}