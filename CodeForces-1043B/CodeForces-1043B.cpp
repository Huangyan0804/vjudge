#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int n;
int a[1005];
bool solution(int len){
	for (int j = 0; j < n;  j++){
		if(a[j] != a[j % len])
			return false;
	}
	return true;
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = n - 1; i > 0; i--)
		a[i] = a[i] - a[i - 1];
	vector<int> res;
	for (int i = 1 ; i <= n; i++){
		if(solution(i))
			res.push_back(i);
	}
	cout << res.size() << endl;
	for(auto i = 0; i < res.size(); i++){
		cout << res[i] << ' ';
	}
	return 0;
}