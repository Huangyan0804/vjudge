#include<iostream>
#include<algorithm>
using namespace std;
struct s
{
	int weight;
	char color[10];
}mouse[1001];

bool cmp(const s a, const s b) {
	return a.weight > b.weight;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> mouse[i].weight >> mouse[i].color;
	sort(mouse, mouse + n, cmp);
	for (int i = 0; i < n; i++)
		cout << mouse[i].color << endl;
	return 0;
}