#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int m, n;
int ans;
char oil[101][101];
int vis[101][101];
void dfs(int x, int y, int id) {
	if (x < 0 || x >= m || y < 0 || y >= n)
		return;
	if (oil[x][y] != '@' || vis[x][y] != 0)
		return;
	vis[x][y] = id;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i != 0 || j != 0)
				dfs(x + i, y + j, id);
		}
	}

}
int main() {
	while (cin >> m >> n && (m || n)) {
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				cin >> oil[i][j];
		}
		ans = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (oil[i][j] == '@'&&vis[i][j] == 0)
					dfs(i, j, ++ans);
			}
		}
		cout << ans << endl;
	}
	return 0;
}