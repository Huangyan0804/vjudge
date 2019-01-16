#include<iostream>
#include<algorithm>
using namespace std;
struct s
{
	int val;
	int num;
}candy[1001];

bool cmp(const s a, const s b) {
	return a.val > b.val;
}
int main() {
	int n, w;
	double sum = 0;
	cin >> n >> w;
	for (int i = 0; i < n; i++)
		cin >> candy[i].val >> candy[i].num;
	sort(candy, candy + n, cmp);
	int k = 0;
	while (w > 0 && k < n) {
		if (w - candy[k].num > 0) {
			sum += candy[k].val;
			w -= candy[k].num;
			k++;
		}
		else {
			sum += candy[k].val / candy[k].num*w;
			k++;
			w -= w;
		}
	}
	printf("%.1f\n", sum);
	return 0;
}