#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n, k;
double a[100005];
bool judge(long long x){
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
			cnt += a[i] / x;
	}
	if(cnt < k) return true;
	else return false;
}
int binary(long long sum) {
	long long l = 1, r = sum;
	while (l <= r) {
		long long mid = (l + r + 1ll) / 2;
		if (judge(mid)) r = mid - 1;
		else l = mid + 1 ;
	}
	return r;
}

int main(){
	scanf("%d %d", &n, &k);

	long long  sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lf", &a[i]);
		a[i] *= 100;
		sum += a[i];
	}
	long long ans = binary(sum);
	printf("%.2f\n", ans / 100.0);
	return 0;
}
