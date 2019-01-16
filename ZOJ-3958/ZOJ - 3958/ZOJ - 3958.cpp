#include<iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		int feedback[21];
		int tscore = 0, kscore = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> feedback[i];
			if (feedback[i] == 1)
				kscore++;
			else if (feedback[i] == 2)
				tscore++;
			else if (feedback[i] == 3) {
				tscore++;
				kscore++;
			}
			else if (feedback[i] == 4) {
				tscore--;
				kscore--;
			}
		}
		if (tscore == kscore)
			cout << "Draw" << endl;
		else if (tscore > kscore)
			cout << "Tohru" << endl;
		else
			cout << "Kobayashi" << endl;
	}
	return 0;
}