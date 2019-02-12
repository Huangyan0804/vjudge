#include <algorithm>
#include <iostream>
using namespace std;
const int N = 5005;
int f[N][N];
int main() {
  int N, r, w, x, y, n, m;
  cin >> N >> r;
  n = r, m = r;
  for (int i = 0; i < N; i++) {
    cin >> x >> y >> w;
    x++, y++;
    f[x][y] += w;
    n = max(n, x);
    m = max(m, y);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
    }
  }
  int ans = 0;
  for (int i = r; i <= n; i++) {
    for (int j = r; j <= m; j++) {
      ans = max(ans, f[i][j] - f[i - r][j] - f[i][j - r] + f[i - r][j - r]);
    }
  }
  cout << ans << endl;
  return 0;
}