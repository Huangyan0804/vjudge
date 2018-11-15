#include<iostream>
#include<algorithm>
using namespace std;
int n;
int a[102];
int order[102];
bool isordered(){
	for(int i = 1; i <= n; i++){
		if(a[i] != order[i])
			return false;
	}
	return true;
}
int main(){

	cin >> n;

	for(int i = 1 ;i <= n; i++){
		cin >> a[i];
		order[i] = a[i];
	}
	sort(order + 1, order + n + 1);
	int cnt = 0, l, r = 0;
	int flag = 0;
	while(!isordered() && cnt <= 20000){
		flag = 0;
		for(int i = 1; i <= n - 1 && cnt <= 20000; i ++){
			if(a[i] > a[i + 1]){
				if(!flag){
					l = i;
				}
				cnt++;
				flag = 1;
				r = i + 1;
				swap(a[i], a[i + 1]);
				i++;
			}else if(flag > 0){
				break;
			}
		}
		cout << l << ' ' << r << endl;
	}
	return 0;
}