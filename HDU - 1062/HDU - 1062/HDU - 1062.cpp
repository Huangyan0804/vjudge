#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	int t;
	cin >> t;
	getchar();
	while (t--) {
		string orign, improve, word;
		getline(cin, orign);
		for (auto iter = orign.begin(); iter != orign.end(); iter++) {
			auto temp = iter+1;
			if (*iter != ' ') {
				word = word + *iter;
			}
			if (*iter == ' ' || temp == orign.end()) {
				reverse(word.begin(), word.end());
				improve += word;
				word = "";
				if (temp != orign.end())
					improve += " ";
				if (temp == orign.end() && *iter == ' ')//Ω·Œ≤ø’∏Ò
					improve += " ";
			}
		}
		cout << improve << endl;
	}
	return 0;
}