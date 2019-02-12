#include <iostream>
using namespace std;
const int mod = 9901;
int qmi(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans % mod;
}
int sum(int p, int k) {
  if (k == 0) return 1;
  if (k % 2 == 0)
    return (p % mod * sum(p, k - 1) + 1) % mod;
  else
    return (1 + qmi(p, k / 2 + 1)) * sum(p, k / 2) % mod;
}
int main() {
  int a, b;
  cin >> a >> b;
  int ans = 1;
  for (int i = 2; i <= a; i++) {
    int cnt = 0;
    while (a % i == 0) {
      cnt++;
      a /= i;
    }
    // cout << i << ' ' << cnt << endl;
    if (cnt) {
      ans = ans * sum(i, cnt * b) % mod;
    }
  }
  if (!a) ans = 0;
  cout << ans << endl;
  return 0;
}