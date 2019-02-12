#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
using namespace std;
int a[10005], b[10005];
int main() {
  int n, p, h, m;
  cin >> n >> p >> h >> m;
  int x, y;
  map<pair<int, int>, bool> mp;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    if (x > y) swap(x, y);
    if (mp[make_pair(x, y)])
      continue;
    else {
      mp[make_pair(x, y)] = true;
      a[x + 1]--;
      a[y]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    b[i] = b[i - 1] + a[i];
    cout << b[i] + h << endl;
  }
  return 0;
}