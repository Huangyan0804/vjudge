#include <algorithm>
#include <iostream>
using namespace std;
int n, f;
int a[100010];
double sum[100010];
bool check(double val) {
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i] - val;
  }
  double minv = 1000000;
  for (int i = 0, j = f; j <= n; j++, i++) {
    minv = min(minv, sum[i]);
    if (sum[j] >= minv) return true;
  }
  return false;
}
int main() {
  cin >> n >> f;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  double l = 0, r = 2000;
  while (r - l > 1e-6) {
    double mid = (l + r) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  cout << int(r * 1000) << endl;
  return 0;
}