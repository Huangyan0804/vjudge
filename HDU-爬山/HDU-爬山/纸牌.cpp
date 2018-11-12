#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<sstream>
using namespace std;
string zp[52] = { "A1","A2","A3","A4","A5","A6","A7","A8","A9","A10","AJ","AQ", "AK", "B1","B2","B3","B4","B5","B6","B7","B8","B9","B10","BJ","BQ","BK","C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","CJ","CQ","CK","D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","DJ","DQ","DK" };
int zpnum[53] = { 0 };
int sToInt(string s) {
	stringstream ss;
	int ans;
	ss << s;
	ss >> ans;
	return ans;
}
int main() {
	int t;
	cin >> t;
	while(t--){
		memset(zpnum, 0, sizeof(zpnum));
		string s;
		int tempnum = 0;
		for (int i = 1; i <= 51; i++) {
			cin >> s;
			if (s[0] == 'A')
				tempnum = 0;
			else if (s[0] == 'B')
				tempnum = 13;
			else if (s[0] == 'C')
				tempnum = 26;
			else if (s[0] == 'D')
				tempnum = 39;
			if (s[1] == 'J') tempnum += 11;
			 else if (s[1] == 'Q') tempnum += 12;
			else if (s[1] == 'K') tempnum += 13;
			else {
				string tempstring = s.substr(1);
				tempnum = tempnum + sToInt(tempstring);
			}
			zpnum[tempnum] = 1;
		}
		for (int i = 1; i <= 52; i++) {
			if (zpnum[i] == 0) {
				cout << zp[i - 1] << endl;
				break;
			}
		}
	}
	return 0;
}