#include <iostream>
using namespace std;
int main()
{
	int n, a[501];
	long long k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
		long long win=0;
		int winner=a[0];
		for(int i=1; i<n; i++){
			if(winner > a[i]){
				win++;
			}
			else{
				win = 1;
				winner = a[i];
			}
			if(win == k){
				cout << winner << endl;
				return 0;
			}
		}
		cout<< winner << endl;
	return 0;
}