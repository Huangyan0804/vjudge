#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
#define scanff(n) scanf("%d", &n)
const int N = 1005;
int sum[N][N];
int n, c;
vector<int> nums;
struct Point
{
	int x, y;
}point[N];
int get(int x) {
	int l = 0, r = nums.size() - 1;
	while (l < r) {
		int mid = l + r >> 1;
		if (x <= nums[mid]) r = mid;
		else l = mid + 1;
	}
	return r;
} 
bool check(int x) {
	for (int x1 = 0, x2 = 1; x2 < nums.size(); x2++) {
		while (nums[x2] - nums[x1 + 1] + 1 > x) x1++;
		for (int y1 = 0, y2 = 1; y2 < nums.size(); y2++) {
			while (nums[y2] - nums[y1 + 1] + 1 > x) y1++;
			if (sum[x2][y2] - sum[x2][y1] - sum[x1][y2] + sum[x1][y1] >= c)
				return true;
		}
	}
	return false;
}
int main() {
	scanf("%d%d", &c, &n);
	nums.push_back(0);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanff(x);
		scanff(y);
		nums.push_back(x);
		nums.push_back(y);
		point[i].x = x;
		point[i].y = y;
	}
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	for (int i = 0; i < n; i++) {
		int x = get(point[i].x), y = get(point[i].y);
		sum[x][y]++;
	}
	for (int i = 1; i < nums.size(); i++) {
		for (int j = 1; j < nums.size(); j++) {
			sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}
	int l = 1, r = 10000;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << r << endl;
	return 0;
}